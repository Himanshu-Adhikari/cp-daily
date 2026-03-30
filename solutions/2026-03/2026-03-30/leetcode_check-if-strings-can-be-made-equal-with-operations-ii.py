class Solution:
    def checkStrings(self, s1: str, s2: str) -> bool:
        a1,a2,b1,b2="","","",""
        n=len(s1)
        for i in range(n):
            if(i%2):
                a1+=s1[i]
                b1+=s2[i]
            else:
                a2+=s1[i]
                b2+=s2[i]
        return sorted(a1)==sorted(b1) and sorted(a2)==sorted(b2)
