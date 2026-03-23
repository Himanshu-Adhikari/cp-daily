# 📅 Daily CP Solutions — 2026-03-23

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Longest Cycle In A Graph
**Platform:** GeeksforGeeks

Problem Insight:
This problem involves finding the longest cycle in a functional graph, where each node has at most one outgoing edge. Such graphs are composed of components that are trees leading into cycles, or just paths to dead ends.

Approach:
The solution performs a traversal (similar to DFS) starting from each unvisited node. It uses a hash map to store nodes encountered in the current path along with their distances, allowing for cycle detection and length calculation. A global visited array ensures each node is processed efficiently without redundant work.

Time Complexity:
O(V)
Each node and its single outgoing edge are processed at most a constant number of times across all traversals, as nodes are marked globally visited.

Space Complexity:
O(V)
The space usage is dominated by the adjacency list representation, the global visited array, and the hash map which can store up to V entries in the worst case for a single path.

Optimization Notes:
This solution is optimal. It achieves linear time complexity O(V) and linear space complexity O(V), which are the lower bounds for visiting all nodes and edges in the graph.

### 💻 Implementation
```cpp
class Solution {
public:
    int longestCycle(int V, vector<vector<int>>& edges) {
        vector<int>a(V,-1);
        for(auto &c:edges)a[c[0]]=c[1];
        
        vector<int>vis(V,0);
        int ans=-1;
        
        for(int i=0;i<V;i++){
            if(vis[i])continue;
            
            unordered_map<int,int>mp;
            int nx=i,step=0;
            
            while(nx!=-1 && !vis[nx]){
                vis[nx]=1;
                mp[nx]=step++;
                nx=a[nx];
                
                if(nx!=-1 && mp.count(nx)){
                    ans=max(ans,step-mp[nx]);
                    break;
                }
            }
        }
        return ans;
    }
};
```

## 🔹 Leetcode Max Non Negative Path In A Graph
**Platform:** LeetCode

Problem Insight:
The problem requires finding the maximum product path in a grid where movement is restricted to down or right. Due to negative numbers, both the minimum and maximum path products must be tracked at each cell.

Approach:
A dynamic programming approach is used where each dp[i][j] stores a pair: the minimum and maximum product path ending at (i,j). For each cell, the minimum and maximum products are updated by considering values from the cell above (i-1,j) and to the left (i,j-1), multiplying them by grid[i][j], and taking the overall min/max.

Time Complexity:
O(N*M)
Each cell in the N x M grid is visited once, with constant time operations for updates.

Space Complexity:
O(N*M)
A 2D DP table of size N x M is used to store pairs of minimum and maximum products for each cell.

Optimization Notes:
The time complexity is optimal as every cell must be processed. Space complexity can be optimized to O(M) or O(N) by only storing the current and previous rows/columns, as dp[i][j] only depends on dp[i-1][j] and dp[i][j-1].

### 💻 Implementation
```cpp
class Solution {
public:
    #define pi pair<long long,long long>
    #define f first
    #define s second
    
    int maxProductPath(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<pi>>dp(n,vector<pi>(m,{LLONG_MAX,LLONG_MIN}));
        
        dp[0][0]={grid[0][0],grid[0][0]};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i){
                    dp[i][j].s=max({dp[i][j].s,dp[i-1][j].f*1ll*grid[i][j],dp[i-1][j].s*1ll*grid[i][j]});
                    dp[i][j].f=min({dp[i][j].f,dp[i-1][j].f*1ll*grid[i][j],dp[i-1][j].s*1ll*grid[i][j]});
                }
                if(j){
                    dp[i][j].s=max({dp[i][j].s,dp[i][j-1].f*1ll*grid[i][j],dp[i][j-1].s*1ll*grid[i][j]});
                    dp[i][j].f=min({dp[i][j].f,dp[i][j-1].f*1ll*grid[i][j],dp[i][j-1].s*1ll*grid[i][j]});
                }
            }
        }
        
        long long ans=dp[n-1][m-1].s;
        return ans<0?-1:ans%1000000007;
    }
};
```
