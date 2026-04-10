class Solution:
    def find3Numbers(self, arr):
        f,s=float('inf'),float('inf')
        fe=float('inf')
        for i in arr:
            if(i<=fe):fe=i
            elif(i<=s):
                f=fe
                s=i
            else:
                return [f,s,i]
        return []