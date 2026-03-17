# 📅 Daily CP Solutions — 2026-03-17

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Burning Tree
**Platform:** GeeksforGeeks

Problem Insight:
This problem asks for the maximum time required for "fire" to spread from a target node to all other nodes in a tree. This translates to finding the maximum distance from the target node to any other node in the tree.

Approach:
First, the tree is converted into an undirected graph (adjacency list) where each node is connected to its parent and children. Then, a Breadth-First Search (BFS) is performed starting from the target node to find the longest path to any other node, which represents the minimum time.

Time Complexity:
O(N log N)
Building the adjacency list using 'map' involves N distinct node data values as keys, leading to O(N log N) for map insertions/accesses. BFS then takes O(N) time.

Space Complexity:
O(N)
The adjacency list 'm' stores O(N) edges and N keys. The 'vis' map stores O(N) entries, and the queue 'q' stores at most O(N) elements.

Optimization Notes:
The approach is optimal. However, using 'map' for the adjacency list and visited set introduces a logarithmic factor. If node data values are within a constrained integer range, an array of vectors could be used instead of 'map' for O(1) average access, making the overall time complexity O(N). An 'unordered_map' would also achieve O(N) average time complexity.

### 💻 Implementation
```cpp

class Solution {
  public:
        map<int,vector<int>>m;
    void rec(Node*r){
        if(r->left){
            m[r->left->data].push_back(r->data);
            m[r->data].push_back(r->left->data);
            rec(r->left);
        }
        if(r->right){
            m[r->right->data].push_back(r->data);
            m[r->data].push_back(r->right->data);
            rec(r->right);
        }
    }
    int minTime(Node* root, int target) {
        rec(root);
        queue<int>q;
        map<int,int>vis;
        int res=0;
        q.push(target);
        while(!q.empty()){
            int s=q.size();
            while(s--){
                int c=q.front();q.pop();
                vis[c]=1;
                for(auto d:m[c]){
                    if(!vis[d])q.push(d);
                }
            }
            if(q.size())res++;
        }
        return res;
    }
};
```

## 🔹 Leetcode Largest-Submatrix-With-Rearrangements
**Platform:** LeetCode

Problem Insight:
The problem leverages column rearrangements to form the largest submatrix of ones. The key is to transform the matrix into heights of continuous ones in columns.

Approach:
The solution first transforms the matrix cells into the height of continuous '1's ending at that cell. Then, for each row, it sorts these heights in descending order. Finally, it iterates through each sorted row, calculating potential rectangle areas by multiplying the current height by its effective width (index + 1) and updates the maximum result.

Time Complexity:
O(m*n log n)
O(m*n) for preprocessing column heights, O(m*n log n) for sorting m rows of length n, and O(m*n) for final calculation.

Space Complexity:
O(1)
The solution modifies the input matrix in-place and uses constant additional auxiliary space.

Optimization Notes:
The solution is optimal for this approach. The preprocessing and area calculation steps are linear O(m*n), while the sorting step dominates at O(m*n log n). Given that columns can be rearranged, sorting each row's derived heights is a necessary step to efficiently find the widest possible rectangle for each available height.

### 💻 Implementation
```cpp
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& mat) {
        int m=mat.size(),res=0,n=mat[0].size();
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] and mat[i-1][j]){
                    mat[i][j]=1+mat[i-1][j];
                }
            }
        }
        for(int i=0;i<m;i++){
            sort(mat[i].rbegin(),mat[i].rend());
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res=max(res,mat[i][j]*(j+1));
            }
        }
        return res;
    }
};
```
