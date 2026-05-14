class Solution:
    def isGood(self, nums: List[int]) -> bool:
        a=Counter(nums)
        n=len(nums)-1
        for i in range(1,n):
            if(not a[i]): return False
        return a[n]==2
