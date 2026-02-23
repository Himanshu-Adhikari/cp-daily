# 📅 Daily CP Solutions — 2026-02-01

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Maximum-Of-All-Subarrays-Of-Size-K
**Platform:** GeeksforGeeks

Problem Insight:
This problem aims to find the maximum element for every contiguous subarray (sliding window) of a fixed size K in a given array.

Approach:
The solution uses a multiset to maintain elements within the current sliding window. As the window expands, new elements are inserted. Once the window reaches size K, the maximum element (retrieved efficiently from multiset.rbegin()) is recorded, and the element at the window's left end is removed.

Time Complexity:
O(N log K)
Each of the N elements is inserted and removed once from a multiset of size at most K, with each operation taking O(log K) time.

Space Complexity:
O(K)
The multiset stores up to K elements at any given time.

Optimization Notes:
The solution is not optimal. A more efficient O(N) approach exists using a deque (double-ended queue) to maintain elements in decreasing order for constant amortized time window operations.

CODE:

### 💻 Implementation
```cpp
class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        vector<int>res;
        int n=arr.size();
        multiset<int>m;
        for(int i=0,j=0;i<n;i++){
            m.insert(arr[i]);
            if((i-j+1)==k){
                res.push_back(*m.rbegin());
                m.erase(m.find(arr[j++]));
            }
        }
        return res;
    }
};
```

## 🔹 Leetcode 3010 Divide-An-Array-Into-Subarrays-With-Minimum-Cost-I
**Platform:** LeetCode

Problem Insight:
The problem requires finding the minimum sum of three numbers from an array, where the first element of the original array must always be included. The remaining two numbers must be the smallest from the rest of the array.

Approach:
The solution fixes the first element of the array. It then sorts the subarray containing all elements from the second position onwards. Finally, it sums the first element and the two smallest elements from the now-sorted subarray.

Time Complexity:
O(N log N)
Sorting the subarray nums[1:] takes O(N log N) time, where N is the length of the input array.

Space Complexity:
O(N)
The sorted() function creates a new list of size N-1 which is then assigned back to nums[1:], requiring O(N) auxiliary space.

Optimization Notes:
The current solution is not optimal for time complexity. Instead of sorting the entire subarray in O(N log N) time, one could find the two smallest elements from nums[1:] by iterating through it once. This approach would take O(N) time, improving the overall time complexity.

### 💻 Implementation
```py
class Solution:
    def minimumCost(self, nums: List[int]) -> int:
         nums[1:] = sorted(nums[1:])
         return sum(nums[i] for i in range(3))
```
