class Solution:
    def addBinary(self, a: str, b: str) -> str:
        f=a[::-1]
        s=b[::-1]
        n,m=len(f),len(s)
        res=""
        c=0
        i,j=0,0
        while(i<m or j<n or c):
            v=(1 if i<m and s[i]=='1' else 0)+(1 if j<n and f[j]=='1' else 0)+c
            res+=('1' if v%2==1 else '0')
            c=(1 if v>1 else 0)
            if(i<m):i+=1
            if(j<n):j+=1
        return res[::-1]