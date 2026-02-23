# 📅 Daily CP Solutions — 2026-01-19

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Remove K Digits
**Platform:** GeeksforGeeks

Problem Insight:
To obtain the smallest number after removing K digits, a greedy strategy is employed using a monotonic stack. Removing larger digits that precede smaller digits is prioritized.

Approach:
Iterate through the digits, maintaining a stack to build the result such that digits are non-decreasing. If the current digit is smaller than the stack's top and K removals are available, pop from the stack. After processing all digits, if K is still positive, remove remaining digits from the end of the stack. Finally, clean up leading zeros.

Time Complexity:
O(N)
Each digit is pushed and popped from the stack at most once. String operations like extend and join take O(N).

Space Complexity:
O(N)
The stack can store up to N digits in the worst case.

Optimization Notes:
The solution is optimal in terms of time and space complexity (O(N) for both). A minor correction is needed for the final leading zero handling: if the processed string after removing leading zeros is empty, it should return '0'. For example, "100", k=2 should correctly result in "0", not "00", and "100", k=3 should result in "0", not "". The current code's logic `return ''.join(stk[ix:])` needs to be `return ''.join(stk[ix:]) or '0'` to handle these edge cases correctly.

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
The problem requires finding the largest square submatrix whose sum of elements does not exceed a given threshold. This involves both range sum queries and optimization for size.

Approach:
First, a 2D prefix sum array is precomputed to allow O(1) calculation of any submatrix sum. Then, binary search is applied to find the maximum possible side length of the square. For each side length tested by the binary search, an O(M*N) check iterates through all possible square submatrices to see if any meet the sum criteria using the prefix sums.

Time Complexity:
O(M * N * log(min(M, N)))
Prefix sum computation is O(M*N). The binary search performs log(min(M,N)) iterations, and each iteration calls the 'ok' function which iterates through M*N potential squares.

Space Complexity:
O(M * N)
A 2D prefix sum array of size (M+1)x(N+1) is used to store intermediate sums.

Optimization Notes:
The solution is optimal for this problem. The use of 2D prefix sums is the most efficient way to query submatrix sums. Binary searching on the side length is also optimal because the property "a square of size K exists with sum <= threshold" is monotonic. Further improvement to the overall time complexity would likely require a different problem interpretation or constraints.

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
