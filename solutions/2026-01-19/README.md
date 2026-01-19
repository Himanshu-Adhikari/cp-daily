# 📅 Daily CP Solutions — 2026-01-19

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Remove K Digits
**Platform:** GeeksforGeeks

Problem Insight:
To form the smallest number by removing k digits, prioritize removing larger digits from the left side of the number.
This requires building a sequence of digits that is non-decreasing from left to right.

Approach:
Utilize a monotonic increasing stack. Iterate through digits, popping larger digits from the stack (and decrementing k) if the current digit is smaller. Append the current digit. If k is still positive after iterating, remove the remaining k digits from the end of the stack. Finally, trim any leading zeros.

Time Complexity:
O(N)
Each character is pushed onto and popped from the stack at most once. Final string construction is also linear.

Space Complexity:
O(N)
The stack can store up to N characters, and the resulting string also takes up to N characters.

Optimization Notes:
The solution is optimal. It processes each digit of the input string a constant number of times in a single pass, achieving the best possible asymptotic time complexity.

### 💻 Implementation
```py
class Solution:
    def removeKdig(self, s, k):
        if len(s)==k:
            return '0'
        stk=[]
        for ix,c in enumerate(s):
            while stk and stk[-1]>c:
                stk.pop()
                k-=1
                if k==0:
                    stk.extend(s[ix:])
                    break
            if k==0:
                break
            stk.append(c)
        if k>0:
            stk=stk[:-k]
        for ix,c in enumerate(stk):
            if c!='0':
                break
        return ''.join(stk[ix:])
        
```

## 🔹 Leetcode 1292 Maximum Side Length Of A Square With Sum Less Than Or Equal To Threshold
**Platform:** LeetCode

Problem Insight:
The goal is to find the largest square submatrix within a given matrix whose sum of elements does not exceed a specified threshold.

Approach:
The solution first computes a 2D prefix sum array for O(1) sum calculation of any submatrix. It then uses binary search on the possible side lengths, leveraging a helper function to check if a square of a given side length exists that satisfies the sum constraint.

Time Complexity:
O(m * n * log(min(m, n))) because prefix sums are O(m*n), and binary search (log(min(m,n)) iterations) calls a check function that iterates O(m*n) times in the worst case.

Space Complexity:
O(m * n) for storing the 2D prefix sum array.

Optimization Notes:
This solution is optimal. The use of 2D prefix sums and binary search on the answer combines efficient submatrix sum queries with an efficient search strategy for the maximum side length.

### 💻 Implementation
```cpp
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> a(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                a[i + 1][j + 1] = mat[i][j] + a[i + 1][j] + a[i][j + 1] - a[i][j];

        auto ok = [&](int sz) {
            for (int i = 0; i + sz <= m; i++) {
                for (int j = 0; j + sz <= n; j++) {
                    int s = a[i + sz][j + sz]
                          - a[i][j + sz]
                          - a[i + sz][j]
                          + a[i][j];
                    if (s <= threshold) return true;
                }
            }
            return false;
        };

        int l = 0, r = min(m, n), res = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (ok(mid)) res = mid, l = mid + 1;
            else r = mid - 1;
        }
        return res;
    }
};

```
