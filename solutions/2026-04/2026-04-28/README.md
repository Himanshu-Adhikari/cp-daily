# 📅 Daily CP Solutions — 2026-04-28

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Longest-Repeating-Character-Replacement
**Platform:** GeeksforGeeks

Problem Insight:
The problem asks for the longest substring where, by changing at most k characters, all characters in that substring become identical. This is equivalent to finding the longest substring where `(substring_length - max_frequency_of_any_char_in_substring) <= k`.

Approach:
A sliding window approach is used with two pointers, `i` (right) and `j` (left), and a frequency array `a` for characters. The window expands by moving `i` and updating character frequencies and `cur` (the maximum frequency of any character encountered in the current window's history). If the window length `(i - j + 1)` minus `cur` exceeds `k`, the window is invalid, and it shrinks from the left by moving `j` until the condition is met. The maximum valid window length is recorded.

Time Complexity:
O(N)
Both pointers `i` and `j` traverse the string at most once. Frequency array operations (increment/decrement) and `max` operations are O(1) due to the fixed alphabet size.

Space Complexity:
O(1)
A fixed-size array of 26 integers (`a`) is used to store character frequencies, independent of the input string length.

Optimization Notes:
This solution is optimal. It achieves linear time complexity O(N) by processing each character at most twice (once by pointer `i` and once by pointer `j`) and uses constant extra space, which is the best possible for this problem.

### 💻 Implementation
```cpp
class Solution {
  public:
    int longestSubstr(string& s, int k) {
        int res=0;
        int n=s.size(),cur=0;
        vector<int>a(26,0);
        cur=0;
        for(int i=0,j=0;i<n;i++){
            a[s[i]-'A']++;
            cur=max(cur,a[s[i]-'A']);
            while(i-j+1-cur>k){
                a[s[j]-'A']--;
                j++;
            }
            res=max(res,i-j+1);
        }
        return res;
    }
};
```

## 🔹 Leetcode Minimum-Operations-To-Make-A-Uni-Value-Grid
**Platform:** LeetCode

Problem Insight:
All elements must have the same remainder modulo x for equalization to be possible. The minimum sum of absolute differences to a target value occurs when the target is the median of the elements.

Approach:
First, verify that all grid elements share the same remainder modulo x; otherwise, return -1. Flatten the grid into a 1D list, sort it, and then calculate the total operations by summing absolute differences divided by x for each element to the median (or one of the two medians if the count is even).

Time Complexity:
O(N*M log(N*M))
Flattening the grid is O(N*M), followed by sorting the N*M elements which dominates the complexity.

Space Complexity:
O(N*M)
A flattened list containing all N*M grid elements is created.

Optimization Notes:
This solution is largely optimal. The initial modulo check and final sum calculation are linear (O(N*M)). Finding the median typically requires sorting (O(N*M log(N*M))) or a selection algorithm like Quickselect (average O(N*M), worst-case higher or O(N*M) with more complex pivot selection). Given common constraints, sorting is often an acceptable and simpler approach.

### 💻 Implementation
```py
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
```
