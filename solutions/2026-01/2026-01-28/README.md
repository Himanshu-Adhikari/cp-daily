# 📅 Daily CP Solutions — 2026-01-28

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Count-The-Subset-With-Sum-Equal-To-K
**Platform:** GeeksforGeeks

Problem Insight:
The problem asks to count all distinct subsets within a given array that sum up to a specific target value. It is a classic dynamic programming problem often solved by considering each element.

Approach:
The solution uses recursion with memoization (top-down dynamic programming). For each element, it explores two choices: either include the current element in the subset, reducing the target sum, or exclude it, maintaining the target sum. The counts from these two paths are summed up.

Time Complexity:
O(N * K)
Justification: There are N * K unique states (i, k) stored in the memoization map, and each state is computed once in approximately O(1) time (excluding string key generation).

Space Complexity:
O(N * K)
Justification: The memoization map stores up to N * K entries, and the maximum recursion depth is N.

Optimization Notes:
The O(N*K) time and space complexity is generally optimal for this pseudo-polynomial problem. However, using string concatenation to generate keys for the unordered_map is inefficient; a 2D array (dp[N][K]) or an unordered_map with pair<int, int> keys (requiring a custom hash function) would offer better performance.

### 💻 Implementation
```cpp
class Solution {
  public:
    unordered_map<string,int>m;
    int rec(int i,int k,vector<int>&arr){
        if(i==arr.size())return k==0;
        string key=to_string(i)+")"+to_string(k);
        if(m.count(key))return m[key];
        return m[key]=rec(i+1,k,arr)+rec(i+1,k-arr[i],arr);
    }
    int countSubset(vector<int> &arr, int k) {
        // code here
        int sm=accumulate(begin(arr),end(arr),0);
        if(sm<k)return 0;
        return rec(0,k,arr);
    }
};
```

## 🔹 Leetcode 3651 Minimum-Cost-Path-With-Teleportations
**Platform:** LeetCode

Problem Insight:
This is a shortest path problem on a grid, extended with a limited number of "teleport" moves. Teleporting to a new cell is free but consumes one of k allowances, and is only possible if the target cell's entry cost is less than or equal to the current cell's entry cost.

Approach:
The solution models the problem as a shortest path on a state graph using Dijkstra's algorithm. Each state is defined by (current row, current column, number of teleports used) and the priority queue stores (cumulative cost, k_used, row, col). It considers standard moves to adjacent cells (adding their entry cost) and teleport moves to any valid cell with one more k-use (cost 0).

Time Complexity:
O(N^2 M^2 K log(NMK)).
There are N*M*(K+1) states. Each state has up to 2 direct neighbor transitions and, if eligible for teleport, can potentially make N*M teleport transitions. The global optimization `visitedforeachk` is flawed for this problem, making the worst-case number of teleport edges for each node O(NM). With a priority queue, this results in E log V, where V = NMK and E can be up to NMK * NM.

Space Complexity:
O(NMK).
The distance array 'dist' is N x M x (K+1). The priority queue can store up to N*M*(K+1) tuples in the worst case.

Optimization Notes:
The solution is not optimal and contains a critical correctness flaw in its `visitedforeachk` optimization. This array attempts to amortize the search for teleport targets across different source cells (i,j) for a given `currk`, but the condition for valid targets (`c <= grid[i][j]`) depends on the specific `grid[i][j]` value of the source cell. This makes the shared `r` index incorrect, potentially causing valid teleport paths to be missed. Even if corrected to iterate through all N*M potential teleport targets for each valid state, the O(NMK * NM) edges would make the Dijkstra algorithm too slow for the given constraints (e.g., N, M, K up to 50). A more efficient approach for handling dense teleport edges or a different graph transformation would be required.

### 💻 Implementation
```cpp
class Solution {
public:
   
    bool valid(int i, int j){
        return i<n && j<m ; 
    }
    int m ,n ; 
    int minCost(vector<vector<int>>& grid, int k) {
        vector<int>visitedforeachk(k+1,0) ; 
         n = grid.size() ; 
         m = grid[0].size() ; 
        vector<tuple<int,int,int>>vec ; 
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ;j++){
                vec.push_back({grid[i][j] , i ,j}) ; 
            }
        }
        sort(vec.begin() , vec.end()) ;

        priority_queue<tuple<int,int,int,int> , vector<tuple<int,int,int,int>> ,greater<tuple<int,int,int,int>>> pq ; 
        pq.push({0,0,0,0}) ; 
        vector<vector<vector<int>>>dist (n,vector<vector<int>>(m,vector<int>(k+1, INT_MAX)))  ; 
        
        while(!pq.empty()){
            auto[cost , currk ,i ,j ] = pq.top() ; 
            pq.pop() ; 
            if(i==n-1 && j==m-1)return cost;
            int newcost ; 
            if(valid(i+1,j)){
                newcost = cost+grid[i+1][j] ; 
                if(newcost<dist[i+1][j][currk]){
                    pq.push({newcost ,currk ,i+1,j}) ; 
                    dist[i+1][j][currk]=newcost ; 
                }
            }
            if(valid(i,j+1)){
                newcost = cost+grid[i][j+1] ; 
                if(newcost<dist[i][j+1][currk]){
                    pq.push({newcost ,currk ,i,j+1}) ; 
                    dist[i][j+1][currk]=newcost ; 
                }
            }
            if(currk<k){
                int r = visitedforeachk[currk];
                for(; r<vec.size() ; r++){
                    auto[c ,ni ,nj] = vec[r] ; 
                    if(c>grid[i][j])break ; 
                    if(cost<dist[ni][nj][currk+1]){
                        pq.push({cost, currk+1 , ni,nj}) ; 
                        dist[ni][nj][currk+1] = cost ; 
                    }
                }
                visitedforeachk[currk] = r; 
            }

        }
       
        return -1 ;
    }
};
```
