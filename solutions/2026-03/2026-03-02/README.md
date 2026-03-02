# 📅 Daily CP Solutions — 2026-03-02

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Trapping Rain Water
**Platform:** GeeksforGeeks

Problem Insight:
Water trapped at a position is determined by the minimum of the maximum heights of bars to its left and right, minus the current bar's height.

Approach:
First, iterate from left to right to store the maximum height encountered so far to the left of each bar. Then, iterate from right to left, tracking the maximum height to the right and calculating trapped water at each position using the stored left maximum and current right maximum.

Time Complexity:
O(N)
The solution performs two linear passes over the input array.

Space Complexity:
O(N)
An auxiliary array of size N is used to store the left maximums.

Optimization Notes:
The solution is optimal in terms of time complexity. The space complexity can be optimized to O(1) by using a two-pointer approach, which simultaneously finds the left and right maximums without an additional array.

### 💻 Implementation
```cpp
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int m=0,l=0,r=arr.size()-1,ans=0;
        vector<int>a;
        for(auto c:arr){
            a.push_back(m);
            m=max(m,c);
        }
        for (int i=arr.size()-1,m=0;i>=0;i--){
            ans+=max(min(a[i],m)-arr[i],0);
            m=max(m,arr[i]);
        }
        return ans;
    }
    
};
```

## 🔹 Leetcode Minimum-Swaps-To-Arrange-A-Binary-Grid
**Platform:** LeetCode

Problem Insight:
This problem requires determining the minimum swaps to satisfy a trailing zero condition for each row. It can be transformed into finding a valid permutation of rows with minimum swaps.

Approach:
The solution first precomputes the number of trailing zeros for each row. Then, it uses a greedy approach: for each target row position, it finds the first available row from the current position downwards that meets the trailing zero requirement and "bubbles" it up to the current position, counting the swaps.

Time Complexity:
O(N^2)
Initial trailing zero calculation takes O(N^2), and the subsequent greedy row-finding and bubbling takes O(N) operations per row for N rows, totaling O(N^2).

Space Complexity:
O(N)
A vector of size N is used to store the trailing zero counts for each row.

Optimization Notes:
The solution is optimal. The greedy approach correctly minimizes swaps, and the O(N^2) time complexity is necessary because both calculating initial trailing zeros for N rows (each up to N columns) and simulating row shifts can take quadratic time in the worst case.

### 💻 Implementation
```cpp
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> zeroCount(n,0);
        for(int i = 0; i < n; i++){
            for(int j = n-1; j > 0 && grid[i][j] == 0; j--){
                zeroCount[i]++;
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            int j = i;
            while(j < n && zeroCount[j] < n-i-1){
                j++;
            }
            if(j == n) return -1;
            ans += j-i;
            while(j > i){
                swap(zeroCount[j], zeroCount[j-1]);
                j--;
            }
        }
        return ans;
    }
};
```
