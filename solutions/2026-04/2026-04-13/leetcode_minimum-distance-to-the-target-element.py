class Solution:
    def getMinDistance(self, nums: List[int], target: int, start: int) -> int:
        return min(abs(i-start) for i,val in enumerate(nums) if val==target)