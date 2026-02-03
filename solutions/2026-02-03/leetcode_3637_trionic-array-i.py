class Solution:
    def isTrionic(self, nums: List[int]) -> bool:
        l,n=0,len(nums)
        pr=nums[0]-1
        for i in range(n):
            if(nums[i]<=pr):
                break
            pr=nums[i]
            l=i
        pr=nums[-1]+1
        j=n-1
        for i in range(n-1,-1,-1):
            if(nums[i]>=pr):
                break
            pr=nums[i]
            j=i
        pr=nums[l]+1
        if(l==0 or j==n-1 or l>=j):return False
        for i in range(l,j+1):
            if(pr<=nums[i]):return False
            pr=nums[i]
        return True