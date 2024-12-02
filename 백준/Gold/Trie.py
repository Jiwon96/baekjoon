class TrieNode:
    def __init__(self):
        self.word = False
        self.children ={}

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word:str) -> None:
        node = self.root
        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
        node.word = True

    def search(self, word:str) -> bool:
        node = self.root
        for char in word:
            if char not in node.children:
                return False
            node = node.children[char]

        return node.word

    def startWith(self, word:str)->bool:
        node = self.root
        for char in word:
            if char not in node.children:
                return False
            node = node.children[char]

        return True

    def delete(self, word):
        def _delete(node, word, depth):
            if not node:
                return False

            if depth == len(word):
                if not node.word:
                    return False
                node.word = False
                return len(node.children) == 0

            char = word[depth]
            if char in node.children:
                should_delete_child = _delete(node.children[char], word, depth+1)
                if should_delete_child:
                    del node.children[char]
                    return len(node.children) == 0

            return False

        _delete(self.root, word, 0)

    def update(self, old_word, new_word):
        self.delete(old_word)
        self.insert(new_word)


# 사용 예시
trie = Trie()
trie.insert("apple")
print(trie.search("apple"))   # True
trie.update("apple", "apricot")
print(trie.search("apple"))   # False
print(trie.search("apricot")) # True