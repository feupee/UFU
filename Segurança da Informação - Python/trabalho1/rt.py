"""Rainbow Table didática: SHA256(b'GBC083' + senha UTF-8)."""
import argparse
import hashlib
import json
import random
import re
from pathlib import Path

DEFAULT_LIST = Path(__file__).parent / 'data' / 'diceware.wordlist.asc'


def load_words(path=DEFAULT_LIST):
    rows = []
    for line in Path(path).read_text(encoding='utf-8').splitlines():
        match = re.fullmatch(r'([1-6]{5})\s+(\S+)', line)
        if match:
            rows.append((match[1], match[2]))
    if len(rows) != 7776 or len({x[0] for x in rows}) != 7776:
        raise ValueError('Esperadas 7776 entradas Diceware com códigos únicos.')
    words = [word for _, word in sorted(rows)]
    if len(set(words)) != len(words):
        raise ValueError('Palavras duplicadas na lista.')
    return words


def my_hash(password):
    return hashlib.sha256(b'GBC083' + password.encode('utf-8')).digest()


class Space:
    def __init__(self, words, k=1):
        if not words or len(set(words)) != len(words) or k < 1:
            raise ValueError('Lista única não vazia e k >= 1 são necessários.')
        if any(' ' in word for word in words):
            raise ValueError('As palavras não podem conter espaço.')
        self.words, self.k = list(words), k
        self.n = len(words) ** k

    def password(self, index):
        if not 0 <= index < self.n:
            raise ValueError('Índice fora do espaço.')
        digits = []
        for _ in range(self.k):
            index, digit = divmod(index, len(self.words))
            digits.append(self.words[digit])
        return ' '.join(reversed(digits))

    def reduce(self, digest, column):
        # Mistura determinística com separação de domínio e cor de 8 bytes.
        mixed = hashlib.sha256(b'RT-R1' + column.to_bytes(8, 'big') + digest).digest()
        return int.from_bytes(mixed, 'big') % self.n


class RainbowTable:
    def __init__(self, space, width, endpoints):
        if width < 1:
            raise ValueError('Largura deve ser positiva.')
        self.space, self.width, self.endpoints = space, width, endpoints

    @classmethod
    def build(cls, space, height, width, seed=0):
        if not 1 <= height <= space.n or width < 1:
            raise ValueError('Dimensões inválidas.')
        ends = {}
        for start in random.Random(seed).sample(range(space.n), height):
            current = start
            for column in range(width):
                current = space.reduce(my_hash(space.password(current)), column)
            # Nunca descartar inícios que compartilham um final.
            ends.setdefault(current, []).append(start)
        return cls(space, width, ends)

    def lookup(self, target):
        if len(target) != 32:
            raise ValueError('Hash SHA-256 deve ter 32 bytes.')
        checked = set()
        for position in range(self.width - 1, -1, -1):
            current = self.space.reduce(target, position)
            for column in range(position + 1, self.width):
                current = self.space.reduce(my_hash(self.space.password(current)), column)
            for start in self.endpoints.get(current, []):
                if start in checked:
                    continue
                checked.add(start)
                candidate = start
                for column in range(self.width):
                    password = self.space.password(candidate)
                    digest = my_hash(password)
                    if digest == target:
                        return password
                    candidate = self.space.reduce(digest, column)
        return None

    def coverage(self):
        # Auditoria separada: inclui somente posições efetivamente hasheadas.
        seen = set()
        for starts in self.endpoints.values():
            for start in starts:
                current = start
                for column in range(self.width):
                    seen.add(current)
                    current = self.space.reduce(my_hash(self.space.password(current)), column)
        return seen

    def save(self, path):
        obj = {'version': 1, 'hash': 'SHA256(GBC083||UTF8)',
               'reduction': 'SHA256(RT-R1||column_u64be||digest) mod N',
               'words': self.space.words, 'k': self.space.k,
               'width': self.width, 'endpoints': self.endpoints}
        Path(path).write_text(json.dumps(obj, ensure_ascii=False, separators=(',', ':')), encoding='utf-8')

    @classmethod
    def load(cls, path):
        obj = json.loads(Path(path).read_text(encoding='utf-8'))
        if obj['version'] != 1 or obj['hash'] != 'SHA256(GBC083||UTF8)' or obj['reduction'] != 'SHA256(RT-R1||column_u64be||digest) mod N':
            raise ValueError('Formato incompatível.')
        return cls(Space(obj['words'], obj['k']), obj['width'],
                   {int(end): starts for end, starts in obj['endpoints'].items()})


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    sub = parser.add_subparsers(dest='command', required=True)
    h = sub.add_parser('hash'); h.add_argument('password')
    b = sub.add_parser('build')
    b.add_argument('--words', type=int, default=1)
    b.add_argument('--height', type=int, default=500)
    b.add_argument('--width', type=int, default=20)
    b.add_argument('--seed', type=int, default=0)
    b.add_argument('--output', default='tabela.json')
    q = sub.add_parser('lookup'); q.add_argument('table'); q.add_argument('hash')
    args = parser.parse_args()
    if args.command == 'hash':
        print(my_hash(args.password).hex())
    elif args.command == 'build':
        table = RainbowTable.build(Space(load_words(), args.words), args.height, args.width, args.seed)
        table.save(args.output); print('Tabela salva em', args.output)
    else:
        print(RainbowTable.load(args.table).lookup(bytes.fromhex(args.hash)) or 'Não encontrada')


if __name__ == '__main__':
    main()
