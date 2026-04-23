class Solution:
    def canSplit(self, arr):
        sm=sum(arr)
        cur=0
        for i in arr:
            cur+=i
            sm-=i
            if(cur==sm):return True
        return False