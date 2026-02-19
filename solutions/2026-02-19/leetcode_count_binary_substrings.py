class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        res=0
        cur,prv=0,0
        pr=-1
        for i in s:
            if(pr==-1 or i==pr):
                cur+=1
            else:
                res+=min(cur,prv)
                prv=cur
                cur=1
            pr=i
        res+=min(cur,prv)
        return res