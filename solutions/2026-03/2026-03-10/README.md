# 📅 Daily CP Solutions — 2026-03-10

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Subarrays-With-First-Element-Minimum
**Platform:** GeeksforGeeks

Problem Insight:
The problem asks to count, for each element arr[i], the number of subarrays starting at index i for which arr[i] is the minimum element. The total sum of these counts is then returned.

Approach:
A monotonic stack is used to efficiently find the index of the next smaller element (NSE) for each element arr[i]. For each arr[i], the count of subarrays where it is the minimum and starts at i is simply the difference between its NSE index and i. These counts are summed up to get the final result.

Time Complexity:
O(N)
Each element is pushed onto and popped from the stack at most once, and the array is iterated through two times.

Space Complexity:
O(N)
A vector of size N for nx and a stack that can store up to N elements are used.

Optimization Notes:
This solution is optimal. It achieves linear time complexity by using a monotonic stack to find next smaller elements in a single pass, which is the most efficient way to solve this type of problem.

### 💻 Implementation
```cpp
class Solution {
  public:
    int countSubarrays(vector<int> &arr) {
        stack<int>s;
        int n=arr.size();
        vector<int>nx(n,n);
        int res=0;
        for(int i=0;i<n;i++){
            while(!s.empty() and arr[s.top()]>arr[i]){
                nx[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        for(int i=0;i<n;i++){
            res+=(nx[i]-i);
        }
        return res;
    }
};
```

## 🔹 Leetcode 3130 Find All Possible Stable Binary Arrays I
**Platform:** LeetCode

Problem Insight:
This problem asks to count the number of stable binary arrays that can be formed using a specific count of zeros and ones, where no more than 'limit' consecutive identical characters are allowed.

Approach:
The solution uses dynamic programming where dp[i][j][0] is the count of stable arrays with 'i' zeros and 'j' ones ending with a '0', and dp[i][j][1] is similar but ending with a '1'. Transitions are optimized using a prefix-sum-like technique to handle the 'limit' constraint in constant time.

Time Complexity:
O(zero * one)
The solution iterates through all possible combinations of 'zero' (up to 'zero') and 'one' (up to 'one') in a nested loop, performing constant-time operations for each state.

Space Complexity:
O(zero * one)
A 3D DP array of size (zero+1) * (one+1) * 2 is used to store the intermediate results.

Optimization Notes:
The solution is optimal in terms of time complexity, as processing all combinations of zeros and ones is generally required. While space could be optimized to O(zero * limit) or O(one * limit) by only keeping a 'limit'-sized window of previous states, the current O(zero * one) space is typically acceptable for common competitive programming constraints (e.g., zero, one <= 1000) and is simpler to implement.

### 💻 Implementation
```cpp
class Solution {
    const int MOD = 1e9 + 7;
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        int dp[zero + 1][one + 1][2];
        memset(dp, 0, sizeof(dp));
        for (int i = min(zero, limit); i >= 0; i--)
            dp[i][0][0] = 1;
        for (int j = min(one, limit); j >= 0; j--)
            dp[0][j][1] = 1;
        for (int i = 1; i <= zero; i++) {
            for (int j = 1; j <= one; j++) {
                // append 0
                dp[i][j][0] = (0LL + dp[i - 1][j][0] + dp[i - 1][j][1]
                                - (i - 1 - limit >= 0 ? dp[i - 1 - limit][j][1] : 0)
                                + MOD) % MOD;

                // append 1
                dp[i][j][1] = (0LL + dp[i][j - 1][0] + dp[i][j - 1][1]
                                - (j - 1 - limit >= 0 ? dp[i][j - 1 - limit][0] : 0)
                                + MOD) % MOD;
            }
        }
        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};
```
