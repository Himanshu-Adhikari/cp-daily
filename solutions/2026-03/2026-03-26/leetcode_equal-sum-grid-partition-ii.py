class Solution:
   def canPartitionGrid(self, grid):
       return self._solve(grid) or self._solve(list(zip(*grid)))

   def _solve(self, grid):
       m, n = len(grid), len(grid[0])
       total = sum(sum(row) for row in grid)

       bot_freq = defaultdict(int)
       for row in grid:
           for x in row:
               bot_freq[x] += 1

       top_freq = defaultdict(int)
       top_sum = 0

       for i in range(m - 1):
           for j in range(n):
               v = grid[i][j]
               top_sum += v
               top_freq[v] += 1
               bot_freq[v] -= 1

           bot_sum = total - top_sum
           if top_sum == bot_sum:
               return True

           diff = abs(top_sum - bot_sum)
           if top_sum > bot_sum:
               freq, r1, r2 = top_freq, 0, i
           else:
               freq, r1, r2 = bot_freq, i + 1, m - 1

           rows = r2 - r1 + 1
           if rows * n == 1:    
               continue
           elif rows == 1:   
               if grid[r1][0] == diff or grid[r1][n - 1] == diff:
                   return True
           elif n == 1:        
               if grid[r1][0] == diff or grid[r2][0] == diff:
                   return True
           elif freq.get(diff, 0) > 0: 
               return True

       return False