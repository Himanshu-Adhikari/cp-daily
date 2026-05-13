# 📅 Daily CP Solutions — 2026-05-13

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Mother Vertex
**Platform:** GeeksforGeeks

Problem Insight:
A mother vertex can reach all other graph vertices. If one exists, it must be a node in a source strongly connected component in the condensation graph.

Approach:
A depth-first search (DFS) traversal is performed, pushing nodes to a stack in order of their finishing times. The top element of this stack is a candidate mother vertex. A second DFS from this candidate verifies reachability to all other vertices.

Time Complexity:
O(V + E) because the solution involves two full DFS traversals, each visiting every vertex and edge once.

Space Complexity:
O(V + E) due to storing the adjacency list and using auxiliary space for the visited array, stack, and recursion stack, all proportional to V or V+E.

Optimization Notes:
The solution is optimal. Finding a mother vertex requires checking reachability which inherently takes O(V + E) time in a general graph, matching the algorithm's complexity.

### 💻 Implementation
```cpp
class Solution {
  public:
  
    void firstDfs(int node, vector<int>adj[], vector<bool>&vis, 
    stack<int>&st){
        vis[node]=1;
        for(auto &it:adj[node]){
            if(!vis[it]) firstDfs(it, adj, vis, st);
        }
        st.push(node);
    }
    
    void dfs(int node, vector<int>adj[], vector<bool>&vis){
        vis[node]=1;
        for(auto &it:adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis);
            }
        }
    }
  
    int findMotherVertex(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>adj[V];
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }
        
        stack<int>st;
        
        vector<bool>vis(V, 0);
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                firstDfs(i, adj, vis, st);
            }
        }
        
        int node=st.top();
        
        vis=vector<bool>(V, 0);
        
        dfs(node, adj, vis);
        
        for(int i=0; i<V; i++){
            if(!vis[i]) return -1;
        }
        
        return node;
    }
};
```

## 🔹 Leetcode Minimum-Moves-To-Make-Array-Complementary
**Platform:** LeetCode

Problem Insight:
This problem can be reduced to finding an optimal target sum for N/2 pairs. The number of moves for each pair to reach a target sum can be categorized into 0, 1, or 2, allowing for efficient calculation across all possible target sums using a difference array.

Approach:
For each pair (nums[i], nums[n-1-i]), determine the number of operations (0, 1, or 2) required to make its elements sum to any potential target value T. A difference array is used to aggregate these operation counts across all pairs. Iterate through all possible target sums T from 2 to 2*limit, calculating the total operations for each T using the prefix sum of the difference array, and find the minimum.

Time Complexity:
O(N + limit)
The initial loop iterates N/2 times, and the second loop iterates 2*limit times.

Space Complexity:
O(limit)
A vector of size 2*limit + 2 is used to store the difference array.

Optimization Notes:
The solution is optimal. The time complexity of O(N + limit) is excellent because each pair is processed once (N operations), and all possible target sums are considered in a linear scan (limit operations).

CODE:
class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> delta((limit << 1) + 2, 0);

        for (int i = 0; i < n >> 1; i++) {
            int min = nums[i];
            int max = nums[n - 1 - i];
            if (min > max) swap(min, max);

            delta[2] += 2;
            delta[min + 1]--;
            delta[min + max]--;
            delta[min + max + 1]++;
            delta[max + limit + 1]++;
        }

        int res = n, moves = 0;

        for (int targ = 2; targ <= limit * 2; targ++) {
            moves += delta[targ];
            res = min(res, moves);
        }

        return res;
    }
};

### 💻 Implementation
```cpp
class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> delta((limit << 1) + 2, 0);

        for (int i = 0; i < n >> 1; i++) {
            int min = nums[i];
            int max = nums[n - 1 - i];
            if (min > max) swap(min, max);

            delta[2] += 2;
            delta[min + 1]--;
            delta[min + max]--;
            delta[min + max + 1]++;
            delta[max + limit + 1]++;
        }

        int res = n, moves = 0;

        for (int targ = 2; targ <= limit * 2; targ++) {
            moves += delta[targ];
            res = min(res, moves);
        }

        return res;
    }
};
```
