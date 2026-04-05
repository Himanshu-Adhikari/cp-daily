class Solution:
    def totalWays(self, arr, target):
        n=len(arr)
        dp=[[-1 for i in range(2001)] for j in range(n+1)]
        def rec(i,sm):
            if(i==n):return sm==target
            if(dp[i][sm]!=-1):return dp[i][sm]
            res= rec(i+1,sm+arr[i])+rec(i+1,sm-arr[i])
            dp[i][sm]=res
            return res
        return rec(0,0);