# 📅 Daily CP Solutions — 2026-01-18

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Next Element With Greater Frequency
**Platform:** GeeksforGeeks

Problem Insight:
This problem is a variation of the Next Greater Element problem where the comparison criterion is the frequency of elements. For each number, we seek the first number to its right with a greater frequency.

Approach:
First, precompute the frequency of each number in the array. Then, use a monotonic stack to determine the next frequency greater element for each number. Iterate through the array, pushing indices onto the stack, and for each current element, pop elements from the stack whose frequencies are less than the current element's frequency.

Time Complexity:
O(N log U)
Frequency calculation and stack processing each take O(N log U) time due to std::map lookups and insertions, where N is array size and U is unique elements.

Space Complexity:
O(N + U)
The result vector is O(N), the stack is O(N), and the frequency map stores U unique elements in O(U) space.

Optimization Notes:
The current solution uses std::map for frequency counting. Replacing it with std::unordered_map would improve the average time complexity to O(N) by making frequency lookups and insertions O(1) on average.

### 💻 Implementation
```cpp
class Solution {
  public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        map<int,int>m;
        int n=arr.size();
        vector<int>res(n,-1);
        for(int i:arr)m[i]++;
        stack<int>s;
        for(int i=0;i<n;i++){
            while(!s.empty() and m[arr[i]]>m[arr[s.top()]]){
                res[s.top()]=arr[i];
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};

```

## 🔹 Leetcode 1895 Largest Magic Square
**Platform:** LeetCode

Problem Insight:
The problem asks to find the largest square subgrid within a given grid where all row sums, column sums, and both main and anti-diagonal sums are equal. The smallest possible magic square size is 1.

Approach:
The solution iterates through all possible square sizes 'o' from 2 up to the minimum of grid dimensions. For each size 'o', it checks every possible top-left corner (i,j) to define a subgrid. For each subgrid, it explicitly calculates all row sums, column sums, and both diagonal sums, then verifies if they are all equal.

Time Complexity:
O(N * M * min(N,M)^3)
Justification: Outer loops iterate through square sizes 'o' (up to min(N,M)), then top-left coordinates (N*M). Inside, calculating all sums for an 'o'x'o' subgrid takes O(o^2) time.

Space Complexity:
O(min(N,M))
Justification: Two vectors 'rows' and 'cols' of size 'o' are allocated to store sums for the current subgrid. 'o' can be at most min(N,M).

Optimization Notes:
The solution is not optimal. The calculation of row, column, and diagonal sums for each subgrid of size 'o' takes O(o^2) time. This can be significantly improved by precomputing 2D prefix sum arrays (for rows, columns, and both diagonals). With prefix sums, each of the 'o' row sums, 'o' column sums, and 2 diagonal sums can be calculated in O(1) time each, reducing the inner sum calculation from O(o^2) to O(o). This would improve the overall time complexity to O(N * M * min(N,M)^2) after O(N*M) preprocessing.

### 💻 Implementation
```cpp
class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int res = 1;
        int k = min(n, m);

        for (int o = 2; o <= k; o++) {
            for (int i = 0; i + o <= n; i++) {
                for (int j = 0; j + o <= m; j++) {
                    vector<int> rows(o, 0), cols(o, 0);
                    int d1 = 0, d2 = 0;

                    for (int r = 0; r < o; r++) {
                        for (int c = 0; c < o; c++) {
                            int v = grid[i + r][j + c];
                            rows[r] += v;
                            cols[c] += v;
                            if (r == c) d1 += v;
                            if (r + c == o - 1) d2 += v;
                        }
                    }

                    int target = rows[0];
                    bool ok = true;

                    for (int r = 0; r < o; r++)
                        if (rows[r] != target) ok = false;

                    for (int c = 0; c < o; c++)
                        if (cols[c] != target) ok = false;

                    if (d1 != target || d2 != target) ok = false;

                    if (ok) res = o;
                }
            }
        }
        return res;
    }
};

```
