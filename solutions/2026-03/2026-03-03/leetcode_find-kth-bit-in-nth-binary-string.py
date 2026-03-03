class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        s="0"
        while(len(s)<k):
            t=s
            s+='1'
            p=""
            for i in t:
                if i=='1':p+='0'
                else:p+='1'
            s+=p[::-1]
        return s[k-1]