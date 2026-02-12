# 📅 Daily CP Solutions — 2026-02-12

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Max Min Height
**Platform:** GeeksforGeeks

Problem Insight:
Find the maximum possible minimum height across all cells after applying at most k operations. An operation increases height for a cell and w cells to its right.

Approach:
Perform binary search on the target minimum height. For each candidate height, simulate operations using a difference array to check if it's achievable within k operations.

Time Complexity:
O(N log H) where N is array size and H is max possible height. This is due to N elements processed in O(1) inside log H binary search iterations.

Space Complexity:
O(N) for the difference array.

Optimization Notes:
The solution is optimal. Binary search on the answer is standard for "maximize minimum" problems, and the linear-time check function efficiently calculates required operations using a difference array.

### 💻 Implementation
```cpp
class Solution {
public:
    int maxMinHeight(vector<int> &arr, int k, int w) {
        int n = arr.size();
        using ll = long long;

        ll l = 0, h = 1e14;
        ll ans = 0;

        while (l <= h) {
            ll mid = l + (h - l) / 2;

            vector<ll> diff(n + 1, 0);
            ll currWater = 0;
            ll operations = 0;

            for (int i = 0; i < n; i++) {
                currWater += diff[i];
                ll height = arr[i] + currWater;

                if (height < mid) {
                    ll need = mid - height;
                    operations += need;

                    if (operations > k) break;

                    currWater += need;
                    if (i + w < n)
                        diff[i + w] -= need;
                }
            }

            if (operations <= k) {
                ans = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }

        return ans;
    }
};

```

## 🔹 Leetcode 3713 Longest Balanced Substring
**Platform:** LeetCode

Problem Insight:
The goal is to find the longest substring where all characters present within that substring appear an equal number of times.
The solution checks all possible substrings and maintains character frequency distributions to identify balanced ones.

Approach:
The solution uses nested loops to iterate through all possible substrings defined by starting index 'i' and ending index 'j'. For each substring, it tracks character frequencies in 'v' and uses 'aux' to store the counts of distinct frequencies. If 'aux' contains only one entry, the substring is balanced, and its length updates the maximum.

Time Complexity:
O(N^2)
The outer loop runs N times, the inner loop runs N times, and dictionary operations inside are O(1) on average due to constant alphabet size.

Space Complexity:
O(1)
The frequency array 'v' and the frequency-of-frequencies map 'aux' are both bounded by the constant alphabet size (26).

Optimization Notes:
The solution is not optimal for large inputs, running in O(N^2) time, which would be too slow for N up to 10^5.
More efficient solutions for this problem typically achieve O(N * alphabet_size) or O(N * logN * alphabet_size) using techniques like specialized hashing, prefix sums with common frequency targets, or advanced sliding window approaches.

### 💻 Implementation
```py
class Solution:
    def longestBalanced(self, s: str) -> int:
        res = 0
        n = len(s)
        for i in range(n):
            v = [0] * 26
            aux = {}
            for j in range(i, n):
                c = ord(s[j]) - ord('a')
                if v[c] > 0:
                    aux[v[c]] -= 1
                    if aux[v[c]] == 0:
                        del aux[v[c]]
                v[c] += 1
                aux[v[c]] = aux.get(v[c], 0) + 1
                if len(aux) == 1:
                    res = max(res, j - i + 1)
        return res

```
