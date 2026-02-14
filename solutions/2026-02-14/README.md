# 📅 Daily CP Solutions — 2026-02-14

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg The-Painters-Partition-Problem
**Platform:** GeeksforGeeks

Problem Insight:
This is a classic problem to minimize the maximum sum of subarrays when splitting an array into a fixed number of partitions. The answer space for the maximum sum is monotonically searchable.

Approach:
The solution uses binary search on the answer. It guesses a maximum allowed sum for any subarray (mid), then checks if the array can be split into at most K subarrays with each sum not exceeding mid. If it can, it tries a smaller mid; otherwise, it tries a larger mid.

Time Complexity:
O(N * log(SumOfElements))
Each binary search iteration involves a linear O(N) scan to count required subarrays, multiplied by the O(log(SumOfElements)) range for binary search.

Space Complexity:
O(1)
The solution uses a constant number of variables for computation, independent of the input array size.

Optimization Notes:
The solution is optimal for this problem. It uses binary search on the answer, which is the most efficient way to find the minimum possible maximum value, combined with a linear scan to check feasibility for each guessed value.

### 💻 Implementation
```cpp
class Solution {
  public:
    int minTime(vector<int>& arr, int k) {
        #define ll long long
        ll l=*max_element(begin(arr),end(arr)),r=accumulate(begin(arr),end(arr),0ll);
        ll res=r;
        int n=arr.size();
        while(l<=r){
            ll md=l+(r-l)/2;
            ll cnt=0;
            ll sm=0;
            int i=0;
            while(i<n){
                sm=0;
                while(i<n and (sm+arr[i])<=md){
                    sm+=arr[i];
                    i+=1;
                }
                cnt+=1;
            }
            if(cnt<=k){res=md,r=md-1;}
            else l=md+1;
        }
        return res;
    }
};
```

## 🔹 Leetcode Champagne Tower
**Platform:** LeetCode

Problem Insight:
The problem models champagne flow in a pyramid, where excess liquid from a glass splits evenly into the two glasses below. This cascading behavior is naturally suited for dynamic programming, calculating values row by row.

Approach:
A single 1D DP array represents the champagne inflow for the current row's glasses. Iterating from row 1 up to the query row, each glass's overflow from the previous row is calculated. By looping through glass indices in reverse, the DP array can be updated in-place, using old values before they are overwritten to compute the current row's state.

Time Complexity:
O(query_row^2). The outer loop runs query_row times, and the inner loop processes up to row+1 glasses, leading to a quadratic complexity.

Space Complexity:
O(query_row). A single 1D vector of size proportional to query_row (specifically, max_row + 2) is used to store values for only one row at a time.

Optimization Notes:
The solution is optimal. The O(query_row^2) time complexity is inherent to computing values for all relevant glasses up to the query row. The O(query_row) space complexity is optimal because only the previous row's data is needed to calculate the current row, avoiding a larger 2D DP table.

### 💻 Implementation
```cpp
class Solution {
public:
     double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> res(102);
        res[0] = poured;
        for (int row = 1; row <= query_row; row++)
            for (int i = row; i >= 0; i--)
                res[i + 1] += res[i] = max(0.0, (res[i] - 1) / 2);
        return min(res[query_glass], 1.0);
    }
};
```
