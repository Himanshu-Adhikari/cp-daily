class Solution:
    def binaryGap(self, n: int) -> int:
        a=bin(n)[2::]
        pr=-1
        res=0
        for i,v in enumerate(a):
            if(v=='1'):
                if(pr!=-1):res=max(res,i-pr)
                pr=i
        return res