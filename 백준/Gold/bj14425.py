class TrieNode:
    def __init__(self):
        self.word = False
        self.children = {}

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        node = self.root
        for w in word:
            if w not in node.children:
                node.children[w] = TrieNode()
            node = node.children[w]

        node.word=True

    def search(self, word):
        node = self.root
        for w in word:
            if w not in node.children:
                return False
            node = node.children[w]

        return node.word

    def startwith(self, word) -> bool:
        node = self.root
        for w in word:
            if w not in node.children:
                return False
            node = node.children[w]

        return True

    def delete(self, word):
        def _delete(node, word, depth):
            if not node :
                return False

            if depth == len(word):
                if not node.word:
                    return False
                node.word = False
                return len(node.children) == 0

            char = word[depth]

            if char in node.children:
                shouldDelete = _delete(node.children[char], word, depth+1)

                if shouldDelete:
                    del node.children[char]
                    return len(node.children)==0

            return False

        _delete(self.root, word, 0)

N, M = map(int, input().split())
trie = Trie()
ans=0
for _ in range(N):
    trie.insert(input())

for _ in range(M):
    if trie.search(input()):
        ans+=1

print(ans)
