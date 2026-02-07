class Solution:
    def maxSum(self, arr):
        n = len(arr)
        arr_sum = sum(arr)

        curr = sum(i * val for i, val in enumerate(arr))
        res = curr

        for i in range(1, n):
            curr = curr + arr_sum - n * arr[n-i]
            res = max(res, curr)

        return res