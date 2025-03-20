from typing import List

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        lenght = 0
        max_len = 0
        nums_set = set(nums) # remove dupliactes

        for n in nums_set:
            # check if n is the start of sequence
            if n-1 not in nums_set:
                length = 1 # n is the start  of sequence
                while n+length in nums_set:
                    length += 1
                max_len =  max(max_len, length)
        return max_len