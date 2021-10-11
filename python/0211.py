class WordDictionary:

    def __init__(self):
        self.trie = {}

    def addWord(self, word: str) -> None:
        t = self.trie
        for w in word:
            if w not in t:
                t[w] = {}
            t = t[w]
        t['#'] = True

    def search(self, word: str) -> bool:
        def check(idx, trie):
            if idx >= len(word):
                return '#' in trie
            c = word[idx]
            if c == '.':
                for (k, t) in trie.items():
                    if k == '#':
                        continue
                    if check(idx+1, t):
                        return True
            else:
                if c not in trie:
                    return False
                else:
                    if check(idx+1, trie[c]):
                        return True
            return False
        return check(0, self.trie)


obj = WordDictionary()
obj.addWord('bad')
obj.addWord('dad')
obj.addWord('mad')
print(obj.search('pad'))
print(obj.search('bad'))
print(obj.search('.ad'))
print(obj.search('b..'))
