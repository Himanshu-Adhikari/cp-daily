# 📅 Daily CP Solutions — 2026-03-18

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Distribute-Candies-In-A-Binary-Tree
**Platform:** GeeksforGeeks

Problem Insight:
The problem asks for the minimum total moves to redistribute candies in a binary tree so each node eventually holds one candy. Moves occur between adjacent nodes.

Approach:
The solution uses a post-order traversal (DFS). Each node recursively determines the net candy flow (excess or deficit) for its subtree, contributing to the total moves at each step.

Time Complexity:
O(N)
Every node in the tree is visited exactly once during the depth-first search traversal.

Space Complexity:
O(H) where H is the height of the tree.
This accounts for the maximum depth of the recursion stack, which can be O(N) in the worst case for a skewed tree.

Optimization Notes:
The solution is optimal. It correctly computes the minimum moves by summing the absolute net candy flow across each edge. No asymptotic time or space improvements are generally possible for this problem.

### 💻 Implementation
```cpp

class Solution {
  public:
    int res=0;
    int rec(Node *root){
        if(!root)return 0;
        int l=rec(root->left);
        int r=rec(root->right);
        res+=abs(l)+abs(r);
        return root->data+l+r-1;
    }
    int distCandy(Node* root) {
        rec(root);
        return res;
    }
};
```

## 🔹 Leetcode Count-Submatrices-With-Top-Left-Element-And-Sum-Less-Than-K
**Platform:** LeetCode

Problem Insight:
The problem counts submatrices anchored at (0,0) with sums less than or equal to k. It leverages a standard 2D prefix sum technique.

Approach:
The solution constructs a 2D prefix sum array where each element pr[r][c] stores the sum of the submatrix from (0,0) to (r-1,c-1). It iterates through all possible bottom-right corners (i,j), calculates the sum of the submatrix (0,0) to (i,j) using the prefix sum formula, and increments a counter if the sum is within the k limit.

Time Complexity:
O(m*n)
Two nested loops iterate through all m rows and n columns of the grid, performing constant time calculations.

Space Complexity:
O(m*n)
A 2D prefix sum array of size (m+1)x(n+1) is used to store intermediate sums.

Optimization Notes:
The solution is optimal. Calculating the sum for each (0,0) to (i,j) submatrix takes O(1) time after the prefix sum array is built. Since all m*n such submatrices must be considered, O(m*n) time and space are the theoretical minimums.

### 💻 Implementation
```cpp
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n=grid[0].size(),m=grid.size();
        vector<vector<int>>pr(m+1,vector<int>(n+1,0));
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                pr[i+1][j+1]=pr[i+1][j]+pr[i][j+1]-pr[i][j]+grid[i][j];
                if(pr[i+1][j+1]<=k)res+=1;
            }
        }
        return res;
    }
};
```
