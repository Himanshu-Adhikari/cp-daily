class Solution:
    def minRemoval(self, nums: List[int], k: int) -> int:
        n=len(nums)
        i,j=0,0
        res=n-1
        nums.sort()
        while(i<n):
            while(i<n and  nums[i]<=(nums[j]*k)):
                if((n-(i-j+1))<res):
                    res=n-(i-j+1)
                i+=1
            while(i<n and nums[i]>(nums[j]*k)):
                j+=1
        return res