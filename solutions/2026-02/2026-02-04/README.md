# 📅 Daily CP Solutions — 2026-02-04

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Last-Moment-Before-All-Ants-Fall-Out-Of-A-Plank
**Platform:** GeeksforGeeks

Problem Insight:
Ants effectively pass through each other on collision; we only care about their initial direction and position. The last ant to fall off is either the rightmost ant moving left or the leftmost ant moving right.

Approach:
Calculate the time for the rightmost left-moving ant to fall off the left end (distance is its position). Calculate the time for the leftmost right-moving ant to fall off the right end (distance is n minus its position). The maximum of these two times is the answer.

Time Complexity:
O(L + R) where L is the length of 'left' and R is the length of 'right'.
It involves finding the maximum in the 'left' list and the minimum in the 'right' list.

Space Complexity:
O(1)
The solution uses a constant amount of extra space for variables.

Optimization Notes:
This solution is optimal. It needs to examine each ant's position at least once to find the extreme cases, making O(L + R) time complexity the lower bound. The O(1) space is also optimal.

### 💻 Implementation
```py
class Solution:
    def getLastMoment(self, n, left, right):
        return max(max(left) if left else 0,(n-min(right) if right else 0))
```

## 🔹 Leetcode 3640 Trionic Array Ii
**Platform:** LeetCode

Problem Insight:
Finds the maximum sum of a subsequence of the form a < b > c < d, where a, b, c, d are elements from the input array in increasing index order.

Approach:
Uses dynamic programming with O(1) space. It maintains three states: 'a' for max sum of increasing pair (X<Y), 'b' for max sum of peak triplet (X<Y>Z), and 'c' for max sum of a valley-peak quad (X<Y>Z<W). The final result is the maximum value of 'c' encountered.

Time Complexity: O(N)
The solution iterates through the array once. Each step involves constant time operations (comparisons, additions, max).

Space Complexity: O(1)
It uses a fixed number of variables (a, b, c, result, prev, curr) regardless of the input array size.

Optimization Notes:
It is optimal. The problem requires inspecting each element at least once, leading to a lower bound of O(N) time complexity. The solution achieves this with O(1) space complexity, which is the best possible for space.

### 💻 Implementation
```cpp
class Solution {
public:
    long long maxSumTrionic(const vector<int>& nums) {
        const long long INF = -1e17;
        long long result = INF, a = INF, b = INF, c = INF;
        long long prev = nums[0];
        for (size_t i = 1; i < nums.size(); i++) {
            long long curr = nums[i];
            auto na = INF, nb = INF, nc = INF;
            if (curr > prev) { 
                na = max(a, prev) + curr;
                nc = max(b, c) + curr;
            } else if (curr < prev) { 
                nb = max(a, b) + curr;
            }
            a = na, b = nb, c = nc;
            result = max(result, c);
            prev = curr;
        }
        return result;
    }
};
```
