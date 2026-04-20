# 📅 Daily CP Solutions — 2026-04-20

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Count Dearrangements
**Platform:** GeeksforGeeks

Problem Insight:
The problem asks to calculate the number of derangements for a given integer n, representing permutations where no element stays in its original position. The solution implements the standard recursive formula for derangements.

Approach:
The core idea is to use the recursive relation D_n = (n-1)*(D_{n-1} + D_{n-2}) for derangements. Base cases for n=1 (D_1=0) and n=2 (D_2=1) are handled, and the formula is applied for larger values of n.

Time Complexity:
O(2^n)
The recursive structure recomputes overlapping subproblems exponentially, similar to a naive Fibonacci implementation.

Space Complexity:
O(n)
This complexity arises from the maximum depth of the recursion call stack.

Optimization Notes:
The solution is not optimal due to its exponential time complexity from redundant calculations. It can be optimized to O(n) time using dynamic programming, either through memoization (storing computed subproblem results) or tabulation (iteratively computing values from base cases). With tabulation, space can be reduced to O(1) by only storing the two preceding values.

### 💻 Implementation
```cpp
class Solution {
  public:
    int derangeCount(int n) {
        if(n <= 2)
            return n - 1;
        return (n - 1) * (derangeCount(n - 1) + derangeCount(n - 2));
    }
};
 


```

## 🔹 Leetcode Two-Furthest-Houses-With-Different-Colors
**Platform:** LeetCode

Problem Insight:
The problem asks to find the largest possible distance between two houses that have different colors. Houses are represented by an array of colors.

Approach:
The solution uses nested loops to check all possible pairs of houses (i, j) where i is to the left of j. For each pair, it verifies if their colors are distinct. If so, it updates the maximum distance found. The inner loop optimizes by breaking early once a different color is found for a fixed 'i' from the right.

Time Complexity: O(N^2)
The nested loops iterate through approximately N*N pairs in the worst case, where N is the number of houses.

Space Complexity: O(1)
The solution uses a constant amount of extra space for variables, independent of the input size.

Optimization Notes: The solution is not optimal. The problem can be solved in O(N) time by realizing that the maximum distance must always involve either the first house (index 0) or the last house (index N-1). We can find the furthest house with a different color from index 0 and the furthest house with a different color from index N-1, then take the maximum of these two distances.

### 💻 Implementation
```cpp
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int maxDist = -1;
        for(int i = 0; i < n; i++){
            for(int j = n - 1; j > i; j--){
                if(colors[i] != colors[j]){
                    maxDist = max(maxDist, j - i);
                    break;
                }
            }
        }
        return maxDist;
    }
};

```
