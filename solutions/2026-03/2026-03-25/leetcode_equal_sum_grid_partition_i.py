class Solution:
    def canPartitionGrid(self, grid: List[List[int]]) -> bool:
        sm=sum(sum(i) for i in grid)
        curr=0
        for i in grid:
            curr+=sum(i)
            sm-=sum(i)
            if(curr and sm and curr==sm):return True
        sm=sum(sum(i) for i in grid)
        curr=0
        n=len(grid[0])
        m=len(grid)
        for j in range(n):
            for i in range(m):
                curr+=grid[i][j]
                sm-=grid[i][j]
            if(curr and sm and curr==sm):return True
        return False