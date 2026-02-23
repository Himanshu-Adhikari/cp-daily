class Solution:
    def findMinDiff(self, arr,M):
        arr.sort()
        n=len(arr)
        return min(arr[i+M-1]-arr[i] for i in range(n-M+1))