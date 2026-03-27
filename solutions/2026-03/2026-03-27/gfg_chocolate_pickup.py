class Solution:
    def maxChocolate(self, grid):
        n,m=len(grid),len(grid[0])
        memo={}
        def rec(i,j,x):
            if(i>=n or j<0 or j>=m or x<=0 or x>=m):return 0
            ky=tuple([i,j,x])
            if(ky in memo):return memo[ky]
            res=0
            for q in range(-1,2):
                for r in range(-1,2):
                   res=max(res,rec(i+1,j+q,r+x))
            res+=grid[i][j]
            if(j!=x):res+=grid[i][x]
            memo[ky]=res
            return res
        return rec(0,0,m-1)