class Solution:
    def minOperations(self, s: str) -> int:
        a,b=0,0
        f,p="0","1"
        for i in s:
            if(p!=i):b+=1
            if(f!=i):a+=1
            p='1' if p=='0' else '0'
            f='1' if f=='0' else '0'
        return min(a,b)
        