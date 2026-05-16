# 📅 Daily CP Solutions — 2026-05-16

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Smallest Number In Subset
**Platform:** GeeksforGeeks

Problem Insight:
The problem seeks the smallest positive integer that cannot be formed by summing a subset of the given numbers. This is a classic greedy problem that relies on maintaining a cumulative sum.

Approach:
First, sort the input array in non-decreasing order. Iterate through the sorted numbers, maintaining a running sum 'cnt' which represents all integers from 1 up to 'cnt'-1 that can be formed. If the current number is greater than 'cnt', then 'cnt' itself cannot be formed and is the answer. Otherwise, add the current number to 'cnt', extending the range of representable sums.

Time Complexity:
O(N log N)
Sorting the array dominates the time complexity, taking O(N log N), followed by a single linear pass of O(N).

Space Complexity:
O(log N)
Standard library sort in C++ typically uses O(log N) auxiliary space for its internal recursive calls.

Optimization Notes:
The solution is optimal. The greedy strategy correctly finds the smallest non-constructible sum, and the O(N log N) time complexity is dictated by the necessary initial sort, which is the lower bound for comparison-based sorting algorithms.

### 💻 Implementation
```cpp
class Solution {
  public:
    int findSmallest(vector<int> &arr) {
        sort(begin(arr),end(arr));
        int cnt=1;
        int sm=0;
        for(auto c:arr){
            if(c>cnt)return cnt;
            cnt+=c;
        }
        return cnt;
    }
};
```

## 🔹 Leetcode Find Minimum In Rotated Array Ii
**Platform:** LeetCode

Problem Insight:
This problem asks to find the minimum element in a sorted array that has been rotated, allowing for duplicate values.

Approach:
The solution uses a modified binary search. It first skips any leading elements that are identical to the last element of the array. Then, it performs a binary search, comparing the middle element to the last element to narrow down the search space until the minimum is found.

Time Complexity:
O(N) in the worst case. The initial loop can iterate through almost all elements, leading to linear time.

Space Complexity:
O(1). Only a few constant extra variables are used.

Optimization Notes:
This approach is optimal for the problem with duplicates. Due to the presence of duplicate values, it's impossible to guarantee discarding half of the search space in every step, leading to an O(N) worst-case time complexity.

### 💻 Implementation
```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size() - 1;
        int last = nums[n];
        int left = 0, right = n;

        while (left < n && nums[left] == last)
            left++;

        while (left < right) {
            int mid = left + right >> 1;

            if (nums[mid] > last)
                left = mid + 1;
            else
                right = mid;
        }

        return nums[left];
    }
};
```
