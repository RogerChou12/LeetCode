from typing import List
from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagram_map=defaultdict(list)

        for word in strs:
            sort_word=''.join(sorted(word)) # list of characters convert to string
            anagram_map[sort_word].append(word)
        
        return list(anagram_map.values())