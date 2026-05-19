# 📅 Daily CP Solutions — 2026-05-19

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Minimum Multiplications To Reach End
**Platform:** GeeksforGeeks

Problem Insight:
This problem asks for the minimum number of steps to transform a starting number to an ending number using specific modular arithmetic operations, indicating a shortest path problem on an unweighted graph.

Approach:
The solution uses Breadth-First Search (BFS) to explore the state space. It treats numbers 0-999 as nodes in a graph, and operations (multiplying by an array element modulo 1000) as edges. BFS guarantees finding the shortest path in terms of number of steps.

Time Complexity:
O(1000 * arr.size())
There are 1000 possible states (0-999). In BFS, each state is visited at most once, and for each visited state, we iterate through 'arr.size()' possible transitions.

Space Complexity:
O(1000)
The 'dist' vector stores distances for 1000 states, and the queue can hold up to 1000 states in the worst case.

Optimization Notes:
The solution is optimal for this problem. BFS correctly finds the minimum steps in an unweighted graph, and the early exit when the target 'end' is reached prevents unnecessary computation. The state space of 1000 nodes is small, making BFS highly efficient.

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
The task is to find the smallest common element between two given sorted arrays. The sorted property of the input arrays is key to an efficient solution.

Approach:
The solution employs a two-pointer technique. One pointer traverses each array, advancing the pointer corresponding to the smaller element until a common element is found or one array is fully traversed.

Time Complexity:
O(N + M) where N and M are the lengths of nums1 and nums2 respectively. Each element from both arrays is visited at most once in the worst case.

Space Complexity:
O(1). The solution uses a constant amount of extra space for a few integer variables.

Optimization Notes:
The solution is optimal for this problem. A two-pointer approach on sorted arrays achieves linear time complexity, which is the most efficient possible as every element might need to be checked.

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
