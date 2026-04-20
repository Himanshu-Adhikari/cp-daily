# 📅 Daily CP Solutions — 2026-04-20

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Count Dearrangements
**Platform:** GeeksforGeeks

Problem Insight:
The problem calculates the number of derangements for a set of n distinct objects, where no object ends up in its original position.

Approach:
The solution implements the standard recursive formula for derangement numbers D(n) = (n-1) * (D(n-1) + D(n-2)) with base cases D(1)=0 and D(2)=1.

Time Complexity:
O(2^n)
The recursive calls create an exponential number of subproblems, similar to the Fibonacci sequence without memoization.

Space Complexity:
O(n)
The recursion depth can go up to n, requiring O(n) space for the call stack.

Optimization Notes:
This solution is not optimal. It recomputes the same subproblems multiple times, leading to exponential time complexity. It can be optimized to O(n) time complexity by using dynamic programming with memoization (top-down) or an iterative approach (bottom-up) to store and reuse previously computed derangement counts.

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
The problem aims to find the maximum distance between two houses in a row that have different colors.

Approach:
The solution uses a brute-force approach, iterating through all possible pairs of houses (i, j) where i < j. For each pair, it checks if their colors differ. If they do, it calculates the distance j - i and updates the overall maximum distance. The inner loop includes a break statement to find the largest j for a given i that maximizes j-i.

Time Complexity:
O(N^2) because the nested loops iterate through approximately N*N/2 pairs in the worst case.

Space Complexity:
O(1) because only a few constant extra variables are used for storage.

Optimization Notes:
The solution is not optimal. An O(N) approach exists. The maximum distance must involve either the first house (index 0) or the last house (index n-1). The optimal solution can be found by taking the maximum of: (1) the distance from index 0 to the rightmost house with a different color, and (2) the distance from the leftmost house with a different color to index n-1. Both distances can be found by single linear scans.

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
