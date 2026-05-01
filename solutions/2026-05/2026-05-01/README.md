# 📅 Daily CP Solutions — 2026-05-01

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Kth Largest In Stream
**Platform:** GeeksforGeeks

Problem Insight:
This solution addresses the classic Kth largest element in a data stream problem, where for each new element, the Kth largest element seen so far must be reported. It leverages a priority queue to efficiently track these elements.

Approach:
The core idea is to maintain a min-priority queue of size K. For each number in the stream, it is added to the priority queue. If the queue's size exceeds K, its smallest element (top) is removed. The Kth largest element seen so far is then always available at the top of this min-priority queue. The provided code uses a max-priority queue storing negative values to achieve min-heap behavior.

Time Complexity:
O(N log K)
Each of N elements involves a push and potentially a pop operation on a priority queue of at most K elements, both taking O(log K) time.

Space Complexity:
O(K)
The priority queue stores at most K elements at any given time.

Optimization Notes:
This approach is optimal for finding the Kth largest element in a stream. It avoids storing all N elements or repeatedly sorting, offering an efficient balance between time and space complexity for this type of problem.

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
The key insight is to observe that the rotate function F(k) for rotation k can be efficiently calculated from F(k-1) by understanding how elements shift. This allows for a dynamic programming approach.

Approach:
Calculate the initial rotate function value F(0) and the total sum of array elements. Then, iteratively compute F(k) for subsequent rotations using the recurrence relation: F(k) = F(k-1) + total_sum - n * nums[element that was last in (k-1)-th rotation]. Keep track of the maximum value found.

Time Complexity:
O(n)
One pass to calculate F(0), one pass to calculate the total sum, and one pass to iteratively compute all F(k) values.

Space Complexity:
O(n)
A vector of size n is used to store all intermediate F(k) values.

Optimization Notes:
The solution is optimal in terms of time complexity. Space complexity can be improved to O(1) by only storing the current F(k) value and the maximum F(k) found so far, instead of storing all F(k) values in a vector.

### 💻 Implementation
```cpp
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        vector<int>sum(n,0);
        for(int i=0;i<n;i++){
            sum[0]+=i*nums[i];
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
