from collections import OrderedDict

class TrieNode:
    def __init__(self):
        self.children = {}

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word_list):
        node = self.root
        for word in word_list:
            if word not in node.children:
                node.children[word] = TrieNode()
            node = node.children[word]

    def show(self):
        def _show(node, depth):
            sorted_d = dict(sorted(node.children.items(), key=lambda x:x[0]))
            for word in sorted_d:
                # create the depth prefix with '-' repeated depth times
                prefix = ''.join(['-'] * (depth * 2))
                # print the prefix followed by the word

                print(prefix + word)
                # recursively call _show for this node's children
                _show(node.children[word], depth + 1)

        _show(self.root, 0)


N = int(input())
trie = Trie()
for _ in range(N):
    lst = list(input().split())
    trie.insert(lst[1:])

trie.show()
