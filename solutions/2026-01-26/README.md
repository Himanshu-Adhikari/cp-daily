# 📅 Daily CP Solutions — 2026-01-26

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Generate Permuation
**Platform:** GeeksforGeeks

Problem Insight:
The problem aims to generate all unique permutations of the elements present in an integer array.

Approach:
The solution sorts the input array initially. It then repeatedly uses the std::next_permutation function to generate all lexicographically subsequent permutations, adding each to a result vector, until no more permutations are possible.

Time Complexity:
O(N * N!) because sorting takes O(N log N), and there are N! permutations, each taking O(N) to generate and O(N) to copy.

Space Complexity:
O(N * N!) because the solution stores N! permutations, each of length N, in the result vector.

Optimization Notes:
This solution is optimal for generating and storing all N! permutations. It inherently requires O(N * N!) time to compute and O(N * N!) space to store all possible permutations.

### 💻 Implementation
```cpp
class Solution {
  public:
    vector<vector<int>> permuteDist(vector<int>& arr) {
        sort(begin(arr),end(arr));
        vector<vector<int>>res;
        do{
            res.push_back(arr);
        }while(next_permutation(begin(arr),end(arr)));
        return res;
    }
};
```

## 🔹 Leetcode Minimum-Absolute-Difference
**Platform:** LeetCode

Problem Insight:
The problem aims to minimize the sum of absolute differences between array elements and a common target value. This sum is minimized when the target value is the median of the array elements.

Approach:
First, sort the given array of integers. Identify the median element from the sorted array (the middle element for odd length, or either of the two middle elements for even length). Finally, calculate the total sum of absolute differences between each element and this median.

Time Complexity: O(N log N)
Sorting the array takes O(N log N) time, and iterating to sum differences takes O(N) time.

Space Complexity: O(log N)
Sorting in-place generally uses O(log N) auxiliary space for recursion stack (or O(1) for heapsort); calculating the sum uses O(1) additional space.

Optimization Notes:
The core idea of using the median is optimal. However, the time complexity can be improved. While sorting takes O(N log N), the median element itself can be found in O(N) average time using a selection algorithm like Quickselect, which would reduce the overall time complexity to O(N).

### 💻 Implementation
```py

```
