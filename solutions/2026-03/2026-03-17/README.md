# 📅 Daily CP Solutions — 2026-03-17

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Burning Tree
**Platform:** GeeksforGeeks

Problem Insight:
This problem asks for the maximum time to burn all nodes in a tree starting from a target node. It is equivalent to finding the maximum distance from the target node to any other node in the tree.

Approach:
First, the binary tree is transformed into an undirected graph using an adjacency list. Then, a Breadth-First Search (BFS) is performed starting from the target node to simulate the burning process, level by level. Each level completed in the BFS represents one unit of time.

Time Complexity:
O(N log N)
The graph conversion and the BFS both involve iterating through all N nodes and N-1 edges. Operations on std::map (like insertion or access) take O(log N) time, contributing to the overall complexity.

Space Complexity:
O(N)
The solution uses a map for the adjacency list, a queue for BFS, and another map for visited nodes, all of which store information proportional to the number of nodes N. The recursion stack for graph conversion also uses O(N) in the worst case.

Optimization Notes:
The solution is not optimal in terms of time complexity. Using std::unordered_map instead of std::map for the adjacency list and visited set would reduce the average time complexity from O(N log N) to O(N), which is typically the optimal time for graph traversal problems. The space complexity O(N) is generally optimal for this type of problem.

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
The problem involves finding the largest submatrix of ones given the ability to rearrange matrix columns. This can be solved by transforming the problem into finding the largest rectangle in a histogram for each row.

Approach:
First, compute the height of consecutive ones for each cell as if it were the bottom of a column. Then, for each row, sort these column heights in descending order to group tall columns together. Finally, iterate through each sorted row, calculating the area formed by current height and available width (number of columns to its left including itself) and update the maximum area.

Time Complexity:
O(m * n log n)
The time is dominated by sorting each of the m rows, where each row has n elements, taking O(n log n) per row.

Space Complexity:
O(1)
The solution modifies the input matrix in-place without allocating significant additional data structures.

Optimization Notes:
The solution is optimal in terms of time complexity for this approach, as sorting rows is the bottleneck and seems necessary to handle column rearrangements effectively. The space complexity is also optimal as it uses O(1) auxiliary space.

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
