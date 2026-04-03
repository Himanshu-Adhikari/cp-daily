# 📅 Daily CP Solutions — 2026-04-03

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Print Diagonally
**Platform:** GeeksforGeeks

Problem Insight:
The problem requires traversing a 2D matrix and collecting all its elements in a specific anti-diagonal order. This order groups elements where the sum of their row and column indices is constant.

Approach:
The solution traverses anti-diagonals in two phases. First, it iterates through the top row, starting a new anti-diagonal from each column and moving downwards-right to upwards-left until hitting matrix boundaries. Second, it continues this process by iterating through the last column (excluding the first row), similarly collecting elements for the remaining anti-diagonals.

Time Complexity:
O(N*M)
Every element in the N x M matrix is visited and added to the result exactly once.

Space Complexity:
O(N*M)
A list of size N*M is used to store all the elements of the matrix as required by the problem.

Optimization Notes:
The solution is optimal. The time complexity is O(N*M) because all elements must be visited. The space complexity is O(N*M) because all elements must be stored in the result list. No further asymptotic improvements are possible.

### 💻 Implementation
```py
class Solution:
    def diagView(self, mat): 
       res=[]
       n,m=len(mat),len(mat[0])
       for j in range(0,m):
           i,k=0,j
           while(i<n and j>=0):
               res.append(mat[i][j])
               i+=1
               j-=1
       for i in range(1,n):
            k,j=i,m-1
            while(k<n and j>=0):
               res.append(mat[k][j])
               k+=1
               j-=1
       return res
```

## 🔹 Leetcode Maximum-Walls-Destroyed-By-Robots
**Platform:** LeetCode

Problem Insight:
The core problem is to maximize walls destroyed by robots, where each robot can only destroy walls to its left OR its right. If adjacent robots claim walls in the segment between them, only one robot can destroy those walls.

Approach:
The solution uses dynamic programming. It first preprocesses the counts of walls each robot can destroy to its left (restricted by the previous robot) and to its right (restricted by the next robot), and the total walls between adjacent robots. Then, it iterates through the sorted robots, maintaining two DP states: maximum walls destroyed ending with the current robot choosing left, and maximum walls destroyed ending with the current robot choosing right, combining these based on the previous robot's choice and handling shared wall segments.

Time Complexity:
O(N log N + M log M + N log M)
Sorting robots is O(N log N), sorting walls is O(M log M). The first loop iterates N times, performing bisect operations on walls (length M), costing O(N log M). The second loop is O(N).

Space Complexity:
O(N + M)
Storing robots positions, distances, and mapping takes O(N). Storing walls takes O(M). The three DP arrays (left, right, num) take O(N) space.

Optimization Notes:
The solution is optimal. It uses sorting for efficient range queries (bisect) and a linear scan dynamic programming approach to combine choices, which is the most efficient way to solve this type of problem. No further asymptotic improvements are typically possible.

### 💻 Implementation
```py
class Solution:
    def maxWalls(
        self, robots: List[int], distance: List[int], walls: List[int]
    ) -> int:
        n = len(robots)
        left = [0] * n
        right = [0] * n
        num = [0] * n
        robots_to_distance = {}

        for i in range(n):
            robots_to_distance[robots[i]] = distance[i]

        robots.sort()
        walls.sort()

        for i in range(n):
            pos1 = bisect.bisect_right(walls, robots[i])

            if i >= 1:
                left_bound = max(
                    robots[i] - robots_to_distance[robots[i]], robots[i - 1] + 1
                )
                left_pos = bisect.bisect_left(walls, left_bound)
            else:
                left_pos = bisect.bisect_left(
                    walls, robots[i] - robots_to_distance[robots[i]]
                )

            left[i] = pos1 - left_pos

            if i < n - 1:
                right_bound = min(
                    robots[i] + robots_to_distance[robots[i]], robots[i + 1] - 1
                )
                right_pos = bisect.bisect_right(walls, right_bound)
            else:
                right_pos = bisect.bisect_right(
                    walls, robots[i] + robots_to_distance[robots[i]]
                )

            pos2 = bisect.bisect_left(walls, robots[i])
            right[i] = right_pos - pos2

            if i == 0:
                continue

            pos3 = bisect.bisect_left(walls, robots[i - 1])
            num[i] = pos1 - pos3

        sub_left, sub_right = left[0], right[0]
        for i in range(1, n):
            current_left = max(
                sub_left + left[i],
                sub_right - right[i - 1] + min(left[i] + right[i - 1], num[i]),
            )
            current_right = max(sub_left + right[i], sub_right + right[i])
            sub_left, sub_right = current_left, current_right

        return max(sub_left, sub_right)
```
