class Solution:
    def maximumAmount(self, coins: List[List[int]]) -> int:
        n=len(coins)
        m=len(coins[0])
        dp = [[[None]*3 for _ in range(m)] for _ in range(n)] 
        def rec(i,j,pw):
            if (i<0 or j<0 or i>=n or j>=m):return -float('inf')
            if(i==n-1 and j==m-1):
                if(coins[i][j]<0 and pw>0):
                    return 0
                return coins[i][j]
            a=(i,j,pw)
            if(dp[i][j][pw] is not None):
                return dp[i][j][pw]
            ans=coins[i][j]+max(rec(i+1,j,pw),rec(i,j+1,pw))
            if(coins[i][j]<0 and pw>0):
                ans=max(ans,max(rec(i+1,j,pw-1),rec(i,j+1,pw-1)))
            dp[i][j][pw]=ans
            return ans
        return rec(0,0,2)