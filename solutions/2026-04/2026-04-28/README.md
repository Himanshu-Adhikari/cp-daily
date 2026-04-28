# 📅 Daily CP Solutions — 2026-04-28

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Longest-Repeating-Character-Replacement
**Platform:** GeeksforGeeks

Problem Insight:
Find the longest substring where the count of the most frequent character plus k replacements can cover the entire substring length. This means (window length - max frequency) <= k.

Approach:
A sliding window expands to the right, maintaining character counts and the maximum frequency within the window. If the number of characters needing replacement (window length minus max frequency) exceeds k, the window shrinks from the left. The maximum valid window length is tracked.

Time Complexity:
O(n)
Both pointers (i and j) traverse the string at most once, and operations inside the loop are constant time.

Space Complexity:
O(1)
A fixed-size array (26 for uppercase English letters) is used to store character frequencies.

Optimization Notes:
The solution is optimal. It processes each character of the string a constant number of times, achieving linear time complexity. The space complexity is also optimal as it uses constant extra space.

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
The problem requires making all grid elements equal by adding or subtracting 'x'. This implies all elements must have the same remainder when divided by 'x', and the goal is to minimize total operations to a common target.

Approach:
The solution first verifies that all grid elements have the same remainder modulo 'x'. If not, it returns -1. It then flattens the grid into a 1D list and sorts it. The target value for operations is intended to be the median of this sorted list. Finally, it attempts to calculate the total operations by summing the absolute differences divided by 'x' for all elements, though it iterates over the original grid for this sum.

Time Complexity:
O(NM log(NM)). The dominant operation is sorting the flattened list, which contains NM elements.

Space Complexity:
O(NM). A new list 'l' is created to store all NM elements of the grid.

Optimization Notes:
The core idea of checking modulo consistency and using the median to minimize operations is optimal. However, the provided code contains a critical bug: the 'rec' function incorrectly iterates over the original 2D grid instead of the flattened 1D list 'l' when calculating the sum of operations, leading to incorrect results. Assuming this bug is fixed, further optimization for very large grids could involve using a linear-time median-finding algorithm (like Quickselect) to reduce the time complexity from O(NM log(NM)) to O(NM) by avoiding a full sort.

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
