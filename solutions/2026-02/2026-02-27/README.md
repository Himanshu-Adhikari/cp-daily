# 📅 Daily CP Solutions — 2026-02-27

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg No Of Submatrix Have Sum K
**Platform:** GeeksforGeeks

Problem Insight:
The problem requires counting all square submatrices within a given 2D integer matrix whose elements sum up to a target value 'x'. This involves efficiently calculating submatrix sums.

Approach:
The solution first precomputes a 2D prefix sum (integral image) matrix, enabling O(1) retrieval of any submatrix sum. It then iterates through every cell as a potential top-left corner and for each, iterates through all possible square sizes starting from 1. For each potential square, it calculates its sum using the precomputed prefix sum and increments a counter if the sum matches 'x'.

Time Complexity:
O(N * M * min(N, M))
Prefix sum computation takes O(N*M). Iterating through all N*M possible top-left corners and then up to min(N,M) possible square sizes for each, with O(1) sum retrieval, leads to the overall complexity.

Space Complexity:
O(N * M)
An additional 2D array of size N*M is used to store the prefix sums.

Optimization Notes:
This approach is a standard and generally effective method for this type of problem involving arbitrary submatrix sums. For general integer matrices and an arbitrary target sum 'x', checking all squares with O(1) sum retrieval is reasonable. The cubic time complexity (in terms of the smaller dimension) makes it feasible for smaller matrices (N, M up to 200-500) but too slow for larger inputs (N, M >= 1000). Further optimizations are typically specific to constraints on matrix values or 'x'.

### 💻 Implementation
```cpp
class Solution
{
public:
    int countSquare(vector<vector<int>> &mat, int x)
    {
        // code here
        int n = mat.size(), m = mat[0].size();

        // Step 1: Create prefix sum matrix
        vector<vector<int>> prefix(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                prefix[i][j] = mat[i][j];

                // Add top
                if (i > 0)
                    prefix[i][j] += prefix[i - 1][j];
                // Add left
                if (j > 0)
                    prefix[i][j] += prefix[i][j - 1];
                // Subtract overlap
                if (i > 0 && j > 0)
                    prefix[i][j] -= prefix[i - 1][j - 1];
            }
        }

        int count = 0;

        // Step 2 : Try all square sizes
        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < m; c++)
            {
                // Mixmun possible size form this position
                for (int size = 1;
                     r + size - 1 < n && c + size - 1 < m; size++)
                {
                    int br = r + size - 1;
                    int bc = c + size - 1;
                    int sum = prefix[br][bc];

                    if (r > 0)
                        sum -= prefix[r - 1][bc];

                    if (c > 0)
                        sum -= prefix[br][c - 1];

                    if (r > 0 && c > 0)
                        sum += prefix[r - 1][c - 1];

                    if (sum == x)
                        count++;
                }
            }
        }
        return count;
    }
};
```

## 🔹 Leetcode Minimum-Operations-To-Equalize-Binary-String
**Platform:** LeetCode

Problem Insight:
This problem aims to find the minimum operations to transform a binary string into all '1's by repeatedly flipping substrings of length 'k'. It's modeled as a shortest path problem where states are counts of '0's.

Approach:
A Breadth-First Search (BFS) explores the state space, where each state is the number of '0's. For a given state 'm', all reachable next states form a contiguous range. A SortedList data structure efficiently handles finding and removing unvisited nodes within this range.

Time Complexity:
O(N log N)
Each of the N+1 states (from 0 to N '0's) is processed once. For each state, operations on the SortedList (bisect_left and pop) take O(log N) time, totaling N log N over all state transitions.

Space Complexity:
O(N)
The distance array, the BFS queue, and the two SortedLists each store up to N+1 elements, resulting in linear space usage proportional to the string length.

Optimization Notes:
The solution is optimal for this type of problem. The use of a SortedList to efficiently manage and prune ranges of unvisited states during BFS is a standard technique that achieves the best possible complexity of N log N for N states.

### 💻 Implementation
```py
class Solution:
    def minOperations(self, s: str, k: int) -> int:
        n, m = len(s), s.count("0")
        dist = [math.inf] * (n + 1)
        nodeSets = [
            SortedList(range(0, n + 1, 2)),
            SortedList(range(1, n + 1, 2)),
        ]
        q = deque([m])
        dist[m] = 0
        nodeSets[m % 2].remove(m)
        while q:
            m = q.popleft()
            c1, c2 = max(k - n + m, 0), min(m, k)
            lnode, rnode = m + k - 2 * c2, m + k - 2 * c1
            nodeSet = nodeSets[lnode % 2]
            idx = nodeSet.bisect_left(lnode)
            while idx < len(nodeSet) and nodeSet[idx] <= rnode:
                m2 = nodeSet[idx]
                dist[m2] = dist[m] + 1
                q.append(m2)
                nodeSet.pop(idx)
        return -1 if dist[0] == math.inf else dist[0]
```
