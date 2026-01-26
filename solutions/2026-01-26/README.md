# 📅 Daily CP Solutions — 2026-01-26

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Generate Permuation
**Platform:** GeeksforGeeks

Problem Insight:
The problem requires generating all distinct permutations of a given array of integers. The solution leverages a standard library function for this purpose.

Approach:
The array is first sorted to get the lexicographically smallest permutation. Then, std::next_permutation is repeatedly called to generate all subsequent permutations in lexicographical order, adding each to the result.

Time Complexity:
O(N * N!)
Sorting takes O(N log N). There are N! permutations, and each call to next_permutation along with copying the array takes O(N) time.

Space Complexity:
O(N * N!)
The result stores N! permutations, each of size N.

Optimization Notes:
Optimal. Generating and storing all N! permutations inherently requires O(N * N!) time and space. The use of std::next_permutation is an efficient way to achieve this.

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
The minimum absolute difference between any two numbers in an array will always be found between adjacent elements after the array is sorted.

Approach:
The solution first sorts the input array. It then performs one pass to find the minimum absolute difference among all adjacent pairs. A second pass is then made to collect all pairs that achieve this minimum difference into the result list.

Time Complexity: O(N log N)
Sorting the array takes O(N log N) time, which dominates the two subsequent linear passes through the array.

Space Complexity: O(N)
The space is primarily used by the sorting algorithm (Python's Timsort uses O(N) auxiliary space in the worst case) and to store the result list, which can contain up to N-1 pairs.

Optimization Notes:
The solution is optimal in terms of time complexity given that sorting is generally required for this problem. The two linear passes after sorting can be combined into a single pass to find the minimum difference and collect pairs simultaneously, slightly improving constant factors but not the Big-O complexity.

### 💻 Implementation
```py
class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        n = len(arr)
        mn = min(arr[i+1] - arr[i] for i in range(n-1))
        res = []
        for i in range(n-1):
            if arr[i+1] - arr[i] == mn:
                res.append([arr[i], arr[i+1]])
        return res

```
