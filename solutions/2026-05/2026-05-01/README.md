# 📅 Daily CP Solutions — 2026-05-01

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Kth Largest In Stream
**Platform:** GeeksforGeeks

Problem Insight:
For each element in the input array, find the k-th largest element among all elements processed up to that point. Output -1 if fewer than k elements are available.

Approach:
Maintain the k largest elements encountered so far in a min-priority queue. For each new element, add it to the queue; if the queue size exceeds k, remove the smallest element. The k-th largest element is then the top of the min-priority queue.

Time Complexity:
O(N log K)
Each of the N input elements involves a push and potentially a pop operation on a priority queue of size at most K, both taking O(log K).

Space Complexity:
O(N + K)
The result vector stores N integers, and the priority queue stores at most K integers.

Optimization Notes:
This solution is optimal for the streaming K-th largest element problem using comparison-based data structures. O(N log K) is the best general-case time complexity. Using `std::priority_queue<int, std::vector<int>, std::greater<int>>` would be a more direct way to implement a min-heap in C++.

### 💻 Implementation
```cpp
class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        priority_queue<int>q;
        vector<int>res;
        for(int i:arr){
            q.push(-i);
            if(q.size()>k)q.pop();
            if(q.size()==k)res.push_back(-q.top());
            else res.push_back(-1);
        }
        return res;
    }
};
```

## 🔹 Leetcode Rotate Function
**Platform:** LeetCode

Problem Insight:
The problem requires finding the maximum value of a rotating sum function, F(k), which is the sum of (index * value) for an array rotated k times.

Approach:
The solution attempts to use a recurrence relation F(k) = F(k-1) + total_sum - n * nums[j] to calculate F values for all rotations. It first tries to compute F(0), then iteratively calculates subsequent F(k) values, storing them in a vector, before finding the maximum. However, the initial calculation of F(0) is incorrect.

Time Complexity: O(N)
The code contains several loops (for F(0) calculation, for total sum, for subsequent F(k) values, and for max element), each iterating up to N times.

Space Complexity: O(N)
A vector 'sum' of size N is used to store all the intermediate F(k) results.

Optimization Notes:
The intended approach using the recurrence relation is time-optimal (O(N)), but the current implementation has a critical bug: the first loop incorrectly calculates sum[0] (which should be F(0)), leading to incorrect results for all F(k). If F(0) were correctly calculated, the space complexity could be optimized to O(1) by only storing the current F value and the maximum F value instead of the entire 'sum' vector.

### 💻 Implementation
```cpp
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        vector<int>sum(n,0);
        for(int i=0;i<n;i++){
            sum[0]=i*nums[i];
        }
        int j=n-1;
        int tot=accumulate(nums.begin(),nums.end(),0);
        for(int i=1;i<n;i++){
            sum[i]=sum[i-1]+tot-n*nums[j--];
        }
        return *max_element(sum.begin(),sum.end());
    }
};
```
