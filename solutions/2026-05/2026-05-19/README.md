# 📅 Daily CP Solutions — 2026-05-19

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Minimum Multiplications To Reach End
**Platform:** GeeksforGeeks

Problem Insight:
This problem maps to finding the shortest path in an unweighted graph where nodes are numbers 0-999 and edges are formed by multiplication modulo 1000.

Approach:
A Breadth-First Search (BFS) is employed to find the minimum number of steps. Starting from the 'start' number, BFS explores reachable numbers level by level until the 'end' number is found, guaranteeing the shortest path.

Time Complexity:
O(1000 * N)
There are 1000 possible states (0-999). For each state, the algorithm iterates through the 'N' factors in 'arr' to find neighbors.

Space Complexity:
O(1000)
The 'dist' array stores distances for 1000 states, and the queue can hold up to 1000 states in the worst case.

Optimization Notes:
The solution is optimal. BFS is the standard algorithm for shortest paths in unweighted graphs, and the fixed state space (0-999) means each state and its transitions are processed efficiently.

### 💻 Implementation
```cpp
// User function Template for C++

class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        // code here
        if (start == end) return 0;
        
        vector<int> dist(1000, -1);
        queue<int> q;
        
        dist[start] = 0;
        q.push(start);
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (int factor : arr) {
                int nextNode = (node * factor) % 1000;
                
                if (dist[nextNode] == -1) {
                    dist[nextNode] = dist[node] + 1;
                    if (nextNode == end) return dist[nextNode];
                    q.push(nextNode);
                }
            }
        }
        
        return -1;
    }
};


```

## 🔹 Leetcode Minimum Common Value
**Platform:** LeetCode

Problem Insight:
The problem asks to find the smallest common element in two non-decreasingly sorted arrays. This requires an efficient way to compare and advance through both lists.

Approach:
The solution uses a two-pointer approach, one for each array. Pointers advance the array with the smaller current element, effectively "discarding" elements that cannot be the smallest common element, until a match is found or one array is fully traversed.

Time Complexity:
O(N + M)
Each pointer traverses its respective array at most once, performing a constant number of operations per step.

Space Complexity:
O(1)
The solution uses only a few integer variables for pointers and array sizes, independent of input size.

Optimization Notes:
This solution is optimal. Since both arrays are sorted, the two-pointer approach examines each element at most once, achieving a linear time complexity proportional to the sum of array lengths, which is the theoretical minimum for this problem. No further improvements in time or space are generally possible for arbitrarily large inputs.

### 💻 Implementation
```cpp
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        int i=0,j=0;
        while(i<n and j<m){
            if(nums1[i]==nums2[j])return nums1[i];
            else if(nums1[i]<nums2[j])i++;
            else j++;
        }
        return -1;

    }
};
```
