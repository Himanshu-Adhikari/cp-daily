class Solution:
    def maxValue(self, nums: List[int]) -> List[int]:
        mx=-1
        n=len(nums)
        pm=[0]*n
        sn=[0]*n
        sn[-1]=nums[-1]
        pm[0]=nums[0]
        for i in range(n-2,-1,-1):
            sn[i]=min(sn[i+1],nums[i])
        for i in range(1,n):
            pm[i]=max(nums[i],pm[i-1])
        res=nums[::]
        res[-1]=pm[-1]
        for i in range(n-2,-1,-1):
            if(pm[i]>sn[i+1]):
                res[i]=res[i+1]
            else:
                res[i]=pm[i]
        return res