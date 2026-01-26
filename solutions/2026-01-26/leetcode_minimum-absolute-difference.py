class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        n = len(arr)
        mn = min(arr[i+1] - arr[i] for i in range(n-1))
        res = []
        for i in range(n-1):
            if arr[i+1] - arr[i] == mn:
                res.append([arr[i], arr[i+1]])
        return res
