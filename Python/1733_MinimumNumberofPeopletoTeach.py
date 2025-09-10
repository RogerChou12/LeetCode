from typing import List

class Solution:
    def minimumTeachings(self, n: int, languages: List[List[int]], friendships: List[List[int]]) -> int:
        notCom=set()
        for friends in friendships:
            lan_map={}
            communicate=False
            for lan in languages[friends[0]-1]:
                lan_map[lan]=1
            for lan in languages[friends[1]-1]:
                if lan in lan_map:
                    communicate=True
                    break
            if not communicate:
                notCom.add(friends[0]-1)
                notCom.add(friends[1]-1)
        
        language_count=[0]*(n+1)
        max_language=0
        for friend in notCom:
            for lan in languages[friend]:
                language_count[lan]+=1
                max_language=max(max_language, language_count[lan])
        return len(notCom)-max_language