class Solution:
    def minimumDeletions(self, s: str) -> int:
        n=len(s)
        a,b=s.count('a'),0
        res=a
        for i in range(n):
            if(s[i]=='a'):a-=1
            else:b+=1
            res=min(res,a+b)
        return res