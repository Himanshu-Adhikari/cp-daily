class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        res=[]
        for nm in nums:
            s=str(nm)
            for j in s:
                res.append(ord(j)-ord('0'))
        return res