# 📅 Daily CP Solutions — 2026-01-27

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Word Search
**Platform:** GeeksforGeeks

Problem Insight:
This problem requires traversing a 2D grid to find a specific word by moving to adjacent cells. It is a classic pathfinding challenge that necessitates exploring multiple potential paths and backtracking.

Approach:
The solution employs a Depth-First Search (DFS) algorithm. It iterates through each cell of the grid, initiating a DFS call if the cell matches the first character of the word, and uses backtracking to explore all valid paths.

Time Complexity:
O(R * C * 4^L)
The algorithm starts a DFS from each of R*C cells, and each DFS path can explore up to L steps with 4 possible directions at each step.

Space Complexity:
O(L)
The space complexity is dominated by the recursion stack depth of the DFS, which can go up to the length of the word L.

Optimization Notes:
This solution is optimal for the given constraints. The exponential factor is inherent to the problem's nature, as it must explore all possible paths of the word's length.

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
This is a shortest path problem on a graph with asymmetric edge costs. An edge (u,v) with cost c implies u->v costs c and v->u costs 2c.

Approach:
The solution models the problem as a directed graph where each input edge translates into two directed edges with their respective costs. Dijkstra's algorithm is then applied using a priority queue to find the minimum cost from node 0 to node n-1.

Time Complexity:
O((M+N) log N). Graph construction using map takes O(M log N), and Dijkstra's algorithm, with map lookups and priority queue operations, takes O((M+N) log N), where M is the number of input edges and N is the number of nodes.

Space Complexity:
O(N + M). The adjacency map stores 2M directed edges, the distance array uses O(N) space, and the priority queue stores at most O(N) elements.

Optimization Notes:
The priority queue uses int for distance values, which could lead to overflow if actual path costs exceed INT_MAX. Using long long for priority queue elements would be safer. Replacing std::map with std::vector for the adjacency list would optimize graph construction and access to O(N+M), reducing the overall time complexity for Dijkstra to O((M+N) log N) effectively if priority queue uses long long. Using LLONG_MAX for initial distances would prevent potential issues if a reachable path happens to cost INT_MAX.

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
