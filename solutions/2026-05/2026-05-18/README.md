# 📅 Daily CP Solutions — 2026-05-18

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Maximum Sum Problem
**Platform:** GeeksforGeeks

Problem Insight:
This problem calculates the maximum value obtainable from an integer N by either taking a pre-defined scaled value or recursively splitting N into N/2, N/3, and N/4 and summing their maximum values. The base case is when N is less than 12, returning N.

Approach:
The solution uses direct recursion to implement the problem's value maximization logic. It compares a specific linear approximation (13 * (N/12)) with the sum of recursive calls on the divided parts (N/2, N/3, N/4). The largest of these is returned for N >= 12.

Time Complexity:
O(N^(log_2 3)) without memoization.
Justification: The recursion depth is O(log N) and each call makes 3 sub-calls, leading to an exponential number of redundant computations for overlapping subproblems.

Space Complexity:
O(log N).
Justification: The space is consumed by the recursion stack, which goes as deep as O(log N) due to N being repeatedly divided by at least 2.

Optimization Notes:
The solution is not optimal. It has exponential time complexity because it recomputes the same subproblems multiple times. Memoization (dynamic programming) is necessary to optimize this to O(N) time complexity (where N is the input value) by storing and reusing the results of `maxSum(k)` for each `k` in a map.

### 💻 Implementation
```cpp
class Solution {
  public:
    int maxSum(int n) {
        if(n<12)return n;
        return max(13*(n/12),maxSum(n/2) + maxSum(n/3) + maxSum(n/4));
    }
};
```

## 🔹 Leetcode Jump Game Iv
**Platform:** LeetCode

Problem Insight:
This problem asks for the minimum number of jumps to reach the last index in an array. This is a classic shortest path problem on an implicit graph where nodes are array indices and edges represent possible jumps.

Approach:
The solution uses Breadth-First Search (BFS) to find the shortest path. It starts from index 0 and explores neighbors in layers. Neighbors are: the previous index (i-1), the next index (i+1), and all other indices with the same array value as the current index. A map stores array values and their corresponding indices to efficiently find "same value" jump targets. A visited array prevents revisiting indices and cycles.

Time Complexity:
O(N log N)
Populating the map with N elements into multisets takes O(N log N). Each of N indices is visited at most once by BFS. Jumps to i-1 and i+1 are O(1). Jumps to same-value indices involve iterating a multiset and erasing elements from it. Each index is erased from its multiset at most once, and each erase operation on a multiset takes O(log N) in the worst case, leading to O(N log N) for these operations in total.

Space Complexity:
O(N)
The map stores all N indices across its multisets, taking O(N) space. The BFS queue can hold up to N elements, and the visited array requires O(N) space.

Optimization Notes:
The solution can be optimized to achieve O(N) time complexity. Replace `std::map<int, std::multiset<int>>` with `std::map<int, std::vector<int>>`. After iterating through all same-value jump targets from an index `c`, clear the vector for `arr[c]` (e.g., `m[arr[c]].clear()` or `m.erase(arr[c])`). This ensures each group of same-value indices is processed only once, making the total cost for these jumps O(N). The current modification of a multiset during iteration is also not robust.

### 💻 Implementation
```cpp
class Solution {
public:
    int minJumps(vector<int>& arr) {
        
        map<int,multiset<int>>m;
        int n=arr.size();
        for(int i=0;i<n;i++){
            m[arr[i]].insert(i);
        }
        queue<int>q;
        q.push(0);
        m[arr[0]]. erase(0);
        vector<int>v(n,0);
        int res=0,s=0;
        while(!q.empty()){
            s=q.size();
            while(s--){
                int c=q.front();
                q.pop();
                if(c==n-1)return res;
                if(c<n-1 and !v[c+1]){
                    m[arr[c+1]].erase(c+1);
                    q.push(c+1);v[c+1]=1;
                }
                if(c and !v[c-1]){
                    v[c-1]=1;
                    m[arr[c-1]].erase(c-1);
                    
                    q.push(c-1);
                }
                for(auto id:m[arr[c]]){
                    if(!v[id]){
                        v[id]=1;
                        m[arr[id]].erase(id);
                        q.push(id);
                    }
                }
            }res++;
        }
        return n;
    }
};
```
