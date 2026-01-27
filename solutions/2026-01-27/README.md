# 📅 Daily CP Solutions — 2026-01-27

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Word Search
**Platform:** GeeksforGeeks

Problem Insight:
This is a classic grid traversal problem requiring a search algorithm to find a path that matches a given word. The challenge involves exploring all valid adjacent cells while ensuring no cell is revisited within the current path.

Approach:
The solution employs a Depth-First Search (DFS) with backtracking. It iterates through each cell in the matrix, initiating a DFS if the cell matches the first character of the word. During DFS, cells are temporarily marked as visited to prevent cycles, and the search continues recursively to adjacent cells until the word is found or all paths are exhausted.

Time Complexity:
O(M * N * 3^L)
There are M*N possible starting cells. For each DFS path of length L, at each step, there are at most 3 valid directions (excluding the one just came from).

Space Complexity:
O(L)
The space is used by the recursion call stack, which can go as deep as the length of the word (L).

Optimization Notes:
The solution is generally optimal for the single-word search problem. The M*N*3^L complexity arises from the inherent need to explore all potential paths. Early pruning through character mismatch checks and bounds validation is already incorporated. No significant algorithmic improvements are typically possible for this specific constraint.

CODE:
class Solution {
public:
    vector<pair<int,int>> dir = {
        {0,1},{1,0},{-1,0},{0,-1}
    };

    bool dfs(int i, int j, int k,
             vector<vector<char>>& mat, string& w) {
        if (k == w.size()) return true;
        if (i<0 || j<0 || i>=mat.size() || j>=mat[0].size()
            || mat[i][j] != w[k]) return false;
        char t = mat[i][j];
        mat[i][j] = '#';
        for (auto [x,y] : dir)
            if (dfs(i+x, j+y, k+1, mat, w)) return mat[i][j]=t, true;
        mat[i][j] = t;
        return false;
    }

    bool isWordExist(vector<vector<char>>& mat, string word) {
        for (int i=0;i<mat.size();i++)
            for (int j=0;j<mat[0].size();j++)
                if (mat[i][j]==word[0] && dfs(i,j,0,mat,word))
                    return true;
        return false;
    }
};

### 💻 Implementation
```cpp
class Solution {
public:
    vector<pair<int,int>> dir = {
        {0,1},{1,0},{-1,0},{0,-1}
    };

    bool dfs(int i, int j, int k,
             vector<vector<char>>& mat, string& w) {
        if (k == w.size()) return true;
        if (i<0 || j<0 || i>=mat.size() || j>=mat[0].size()
            || mat[i][j] != w[k]) return false;
        char t = mat[i][j];
        mat[i][j] = '#';
        for (auto [x,y] : dir)
            if (dfs(i+x, j+y, k+1, mat, w)) return mat[i][j]=t, true;
        mat[i][j] = t;
        return false;
    }

    bool isWordExist(vector<vector<char>>& mat, string word) {
        for (int i=0;i<mat.size();i++)
            for (int j=0;j<mat[0].size();j++)
                if (mat[i][j]==word[0] && dfs(i,j,0,mat,word))
                    return true;
        return false;
    }
};

```

## 🔹 Leetcode 3650 Minimum-Cost-Path-With-Edge-Reversals
**Platform:** LeetCode

Problem Insight:
This problem asks for the minimum cost to travel from node 0 to node n-1 in a graph with asymmetric edge costs. Each original edge [u, v, cost C] implies two directed edges: u to v with cost C, and v to u with cost 2C.

Approach:
The solution constructs a directed graph representing these asymmetric costs. It then applies Dijkstra's algorithm, starting from node 0, to find the shortest path to node n-1. A priority queue manages nodes to visit, always exploring the node with the current minimum accumulated cost.

Time Complexity:
O(E log N)
Graph construction iterates through E edges, each involving map lookups taking O(log N). Dijkstra's algorithm runs in O(E log N) on a graph with N nodes and E edges using a binary heap priority queue.

Space Complexity:
O(N + E)
The adjacency list (map) stores up to N nodes and 2E directed edges. The distance array requires O(N) space, and the priority queue stores at most O(N) entries in the worst case.

Optimization Notes:
The primary issue is a type mismatch: the priority queue stores costs as int, which can overflow if accumulated path costs exceed INT_MAX. These costs should be long long. Additionally, using std::map for the adjacency list introduces an O(log N) factor for lookups; a std::vector of vectors or std::unordered_map could offer faster O(1) average time lookups.

### 💻 Implementation
```cpp
class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        map<int,vector<pair<int,int>>>m;
        for(auto c:edges){
            m[c[0]].push_back({c[1],c[2]});
            m[c[1]].push_back({c[0],2*c[2]});
        }
        #define ll long long
        vector<ll>dist(n,INT_MAX);
        priority_queue<pair<int,int>>pq;
        pq.push({0,0});
        dist[0]=0;
        while(!pq.empty()){
            auto [val,u]=pq.top();pq.pop();
            val=-val;
            if(dist[u]<val)continue;
            for(auto [v,uv]:m[u]){
                if(dist[v]>val+uv){
                    dist[v]=val+uv;
                    pq.push({-dist[v],v});
                }
            }
        }
        return dist[n-1]==INT_MAX?-1:dist[n-1];
    }
};
```
