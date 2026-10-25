import tempfile
import unittest
from pathlib import Path
from rt import Space, RainbowTable, my_hash, load_words


class Tests(unittest.TestCase):
    def test_professor_vector(self):
        self.assertEqual(my_hash('1234').hex(), '5042f15f93d4f75df9cdff09d062d607eaa0140a930b9023c43ca7cc58609b8f')

    def test_official_list(self):
        self.assertEqual(len(load_words()), 7776)

    def test_encoding_bijection(self):
        s = Space(['a', 'b', 'c'], 2)
        self.assertEqual(len({s.password(i) for i in range(s.n)}), 9)
        self.assertEqual(s.password(5), 'b c')

    def test_reduction_range(self):
        s = Space(['a', 'b', 'c'], 2)
        for i in range(50):
            self.assertIn(s.reduce(my_hash(str(i)), i), range(s.n))
            self.assertEqual(s.reduce(my_hash(str(i)), i), s.reduce(my_hash(str(i)), i))

    def test_exhaustive_lookup_matches_coverage(self):
        # Oráculo independente: cobertura explícita em universos pequenos.
        for k in (1, 2):
            s = Space(['a', 'b', 'c', 'd'], k)
            for width in (1, 2, 7):
                for seed in range(4):
                    t = RainbowTable.build(s, 2, width, seed)
                    covered = t.coverage()
                    for i in range(s.n):
                        found = t.lookup(my_hash(s.password(i)))
                        self.assertEqual(found is not None, i in covered)
                        if found is not None:
                            self.assertEqual(found, s.password(i))

    def test_duplicate_endpoints_and_roundtrip(self):
        s = Space(['a', 'b', 'c', 'd'], 2)
        t = RainbowTable.build(s, s.n, 15, 7)
        self.assertTrue(any(len(v) > 1 for v in t.endpoints.values()))
        with tempfile.TemporaryDirectory() as folder:
            p = Path(folder) / 'table.json'; t.save(p)
            restored = RainbowTable.load(p)
            for i in range(s.n):
                self.assertEqual(restored.lookup(my_hash(s.password(i))), s.password(i))

    def test_absent_and_invalid(self):
        s = Space(['a', 'b']); t = RainbowTable.build(s, 1, 1)
        self.assertIsNone(t.lookup(my_hash('fora-do-dicionario')))
        with self.assertRaises(ValueError): RainbowTable.build(s, 3, 1)
        with self.assertRaises(ValueError): t.lookup(b'bad')


if __name__ == '__main__':
    unittest.main(verbosity=2)
