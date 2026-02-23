class Solution:
    def getLastMoment(self, n, left, right):
        return max(max(left) if left else 0,(n-min(right) if right else 0))