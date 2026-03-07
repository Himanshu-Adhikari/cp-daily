class Solution:
    def minFlips(self, s: str) -> int:
        t=s+s
        n=len(s)
        a,b=0,0
        res=n
        for i in range(len(t)):
            if t[i]!=('0' if i%2==0 else '1'): a+=1
            if t[i]!=('1' if i%2==0 else '0'): b+=1
            
            if i>=n:
                if t[i-n]!=('0' if (i-n)%2==0 else '1'): a-=1
                if t[i-n]!=('1' if (i-n)%2==0 else '0'): b-=1
            
            if i>=n-1:
                res=min(res,a,b)
        return res