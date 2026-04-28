class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        sm=sum(sum(i) for i in grid)
        if(not all(j % x == grid[0][0] % x for row in grid for j in row)):
            return -1
        l=[i for j in grid for i in j]
        l.sort()
        n=len(grid)*len(grid[0])
        if(n==1):return 0
        def rec(val:int)->int:
            return sum(abs(i-val)//x for j in grid for i in j)
        return min(rec(l[n//2]),rec(l[(n-1)//2]))