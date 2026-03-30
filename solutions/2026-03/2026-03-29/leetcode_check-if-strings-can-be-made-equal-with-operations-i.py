class Solution:
    def canBeEqual(self, s1: str, s2: str) -> bool:
        return s1==s2 or (min(s1[1],s1[3])==min(s2[1],s2[3]) and 
        max(s1[0],s1[2])==max(s2[0],s2[2]) and
        min(s1[0],s1[2])==min(s2[0],s2[2]) 
        and max(s1[1],s1[3])==max(s2[1],s2[3]))