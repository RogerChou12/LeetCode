class Trie:

    def __init__(self):
        self.root = {} # empty dictionary

    def insert(self, word: str) -> None:
        current = self.root
        for letter in word:
            if letter not in current: # letter doesn't exist
                current[letter] = {} # create new node
            current = current[letter] # move to the next node
        current['*'] = {} # the end of word

    def search(self, word: str) -> bool:
        current = self.root
        for letter in word:
            if letter not in current: # if letter is missing, the word doesn't exist
                return False
            current = current[letter] # move to the next node
        return '*' in current # check if it's a complete word

    def startsWith(self, prefix: str) -> bool:
        current = self.root
        for letter in prefix:
            if letter not in current: # if letter is missing, the word doesn't exist
                return False
            current = current[letter] # move to the next node
        return True # the prefix exists


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)