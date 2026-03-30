class Solution:
    def countPartitions(self, arr, diff):
        sm=sum(arr)
        n=len(arr)
        dp=[[-1 for i in range(n*6+1)]for j in range(n+1)]
        def rec(i,curr):
            if(i==n):
                if ((curr-(sm-curr))==diff):
                    return 1
                return 0
            if(dp[i][curr]!=-1):
                return dp[i][curr]
            tk=rec(i+1,curr)+rec(i+1,curr+arr[i])
            dp[i][curr]=tk
            return tk
        return rec(0,0)
        
