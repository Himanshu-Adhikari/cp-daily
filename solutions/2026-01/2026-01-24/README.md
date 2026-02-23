# 📅 Daily CP Solutions — 2026-01-24

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Josephus Problem
**Platform:** GeeksforGeeks

Problem Insight:
The Josephus problem determines the position of the last person remaining in a circle after sequential eliminations.

Approach:
The solution directly simulates the elimination process using a boolean array to mark active or eliminated participants. It iteratively counts the k-th active person, eliminates them, and repeats until only one person is left.

Time Complexity:
O(N^2)
There are N-1 eliminations, and each elimination can involve iterating through up to N positions in the array to find the next active k-th person.

Space Complexity:
O(N)
A vector of size N is used to store the active/inactive status of each person in the circle.

Optimization Notes:
The solution is not optimal. The problem has a known O(N) iterative solution based on the recurrence relation f(n,k) = (f(n-1, k) + k - 1) % n + 1. It can also be solved in O(N log N) using a segment tree or similar data structure to efficiently find the k-th element and remove it.

### 💻 Implementation
```cpp
class Solution {
  public:
    int josephus(int n, int k) {
        // code here
        vector<int> cir(n,1);
        int i=0,z=0,c=0;
        while(z<n-1){
           if(cir[i]==1){
               c++;
               if(c==k){
               cir[i]=0;
               c=0;
               z++;
               }
           }
           i=(i+1)%n;
        }
        for(int i=0;i<n;i++){
            if(cir[i]==1){
                return i+1;
            }
        }
        return -1;
    }
};
```

## 🔹 Leetcode 1877 Minimize-Maximum-Pair-Sum-In-Array
**Platform:** LeetCode

Problem Insight:
The problem asks to partition elements into pairs such that the maximum sum among all pairs is minimized. This requires a strategy to balance the pair sums.

Approach:
The solution sorts the input array. It then greedily pairs the smallest available element with the largest available element, and finds the maximum sum among these pairs.

Time Complexity:
O(N log N)
The dominant operation is sorting the array, which takes N log N time.

Space Complexity:
O(N)
Python's sort (Timsort) uses O(N) auxiliary space in the worst case.

Optimization Notes:
The solution is optimal. Sorting is necessary to identify the smallest and largest elements for greedy pairing, and O(N log N) is the lower bound for comparison-based sorting.

### 💻 Implementation
```py
class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        nums.sort()
        n=len(nums)
        return max(nums[i]+(nums[n-i-1]) for i in range(n//2))
```
