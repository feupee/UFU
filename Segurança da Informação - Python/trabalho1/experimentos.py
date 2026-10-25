"""Experimentos sem dependências externas; resultados em JSON."""
import argparse
import hashlib
import json
import math
import os
import platform
import random
import statistics
import time
import tracemalloc
from pathlib import Path
from rt import Space, RainbowTable, load_words, my_hash, DEFAULT_LIST


def hardware():
    cpu = platform.processor()
    if Path('/proc/cpuinfo').exists():
        cpu = next((line.split(':', 1)[1].strip() for line in Path('/proc/cpuinfo').read_text().splitlines() if line.startswith('model name')), cpu)
    mem = None
    if Path('/proc/meminfo').exists():
        mem = int(Path('/proc/meminfo').read_text().splitlines()[0].split()[1]) * 1024
    elif platform.system() == 'Windows':
        import ctypes
        class MemoryStatus(ctypes.Structure):
            _fields_ = [('length', ctypes.c_ulong), ('load', ctypes.c_ulong)] + [(n, ctypes.c_ulonglong) for n in ['total', 'avail', 'page', 'availpage', 'virtual', 'availvirtual', 'extended']]
        status = MemoryStatus(); status.length = ctypes.sizeof(status)
        if ctypes.windll.kernel32.GlobalMemoryStatusEx(ctypes.byref(status)):
            mem = status.total
    return {'cpu': cpu or 'não identificado', 'logical_cpus': os.cpu_count(),
            'visible_ram_bytes': mem, 'platform': platform.platform(),
            'python': platform.python_version(),
            'cgroup': {name: (Path('/sys/fs/cgroup')/name).read_text().strip() for name in ('cpu.max','memory.max') if (Path('/sys/fs/cgroup')/name).exists()}, 'execution': 'sequencial, um processo; recursos visíveis podem ser do host'}


def wilson(success, count):
    z = 1.96; p = success / count; d = 1 + z*z/count
    center = (p + z*z/(2*count))/d
    half = z*math.sqrt(p*(1-p)/count + z*z/(4*count*count))/d
    return [center-half, center+half]


def run(trials, repeats, out):
    out.mkdir(parents=True, exist_ok=True)
    words = load_words(); results = []
    configs = [(1,100,100), (1,200,50), (1,500,20),
               (2,2000,100), (2,4000,50), (2,10000,20)]
    for k,m,t in configs:
        s = Space(words,k)
        for rep in range(repeats):
            seed = 100 + rep
            begin = time.perf_counter(); table = RainbowTable.build(s,m,t,seed)
            build = time.perf_counter()-begin
            path = out / 'ultima_tabela.json'; table.save(path)
            disk = path.stat().st_size
            # Medição de alocações separada para não contaminar os tempos.
            tracemalloc.start()
            measured = RainbowTable.build(s,m,t,seed)
            _, peak = tracemalloc.get_traced_memory(); tracemalloc.stop()
            del measured
            covered = table.coverage()
            # Mesmo conjunto por k/repetição em todas as configurações; independente dos inícios.
            rng = random.Random(900000 + 1000*k + rep)
            indices = [rng.randrange(s.n) for _ in range(trials)]
            samples = []
            for index in indices:
                target = my_hash(s.password(index))
                begin = time.perf_counter(); found = table.lookup(target)
                elapsed = time.perf_counter()-begin
                if (found is not None) != (index in covered):
                    raise AssertionError('Busca discordou da cobertura exata.')
                if found is not None and my_hash(found) != target:
                    raise AssertionError('Hash recuperado incorreto.')
                samples.append({'index':index,'found':found is not None,'seconds':elapsed})
            successes = sum(x['found'] for x in samples)
            row = {'k':k,'N':s.n,'height':m,'width':t,'seed':seed,
                   'build_s':build,'disk_bytes':disk,'python_peak_bytes':peak,
                   'distinct_covered':len(covered),'coverage':len(covered)/s.n,
                   'unique_ends':len(table.endpoints),'successes':successes,'trials':trials,
                   'success_rate':successes/trials,'wilson95':wilson(successes,trials),
                   'mean_lookup_ms':1000*statistics.mean(x['seconds'] for x in samples),
                   'median_lookup_ms':1000*statistics.median(x['seconds'] for x in samples),
                   'samples':samples}
            results.append(row)
            print(k,m,t,rep, f'sucesso={successes}/{trials} cobertura={row["coverage"]:.4%}', flush=True)
            payload = {'hardware':hardware(),'trials':trials,'repeats':repeats,
                       'list_sha256':hashlib.sha256(DEFAULT_LIST.read_bytes()).hexdigest(),
                       'source':'https://theworld.com/~reinhold/diceware.wordlist.asc',
                       'results':results}
            (out/'resultados.json').write_text(json.dumps(payload,indent=2,ensure_ascii=False),encoding='utf-8')
    path.unlink(missing_ok=True)


if __name__ == '__main__':
    p=argparse.ArgumentParser(); p.add_argument('--trials',type=int,default=200)
    p.add_argument('--repeats',type=int,default=3)
    p.add_argument('--output',type=Path,default=Path('resultados'))
    a=p.parse_args()
    if a.trials<1 or a.repeats<1: p.error('Valores devem ser positivos.')
    run(a.trials,a.repeats,a.output)
