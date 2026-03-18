# 📅 Daily CP Solutions — 2026-03-18

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Distribute-Candies-In-A-Binary-Tree
**Platform:** GeeksforGeeks

Problem Insight:
The problem asks for the minimum number of moves to ensure each node in a tree has exactly one candy, where a move is transferring one candy between adjacent nodes. The total candy in the tree must equal the number of nodes.

Approach:
The solution employs a depth-first search (DFS) post-order traversal. For each node, it recursively calculates the net candy surplus or deficit of its subtrees. The absolute value of these surpluses/deficits, representing candies moved across edges, is added to a global total.

Time Complexity:
O(N)
Each node in the tree is visited exactly once during the depth-first search traversal.

Space Complexity:
O(H) where H is the height of the tree
The space is determined by the maximum depth of the recursion stack, which can be up to N for a skewed tree.

Optimization Notes:
Optimal. The solution correctly calculates the minimum moves by summing the absolute net candy transfers across each edge. Each node and edge is processed once, achieving optimal O(N) time complexity.

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
The solution counts submatrices whose top-left corner is (0,0) and whose sum is less than or equal to k. It iterates through all possible bottom-right corners (i,j).

Approach:
A 2D prefix sum array is used to compute the sum of the submatrix from (0,0) to (i,j) in constant time for each cell. For each (i,j), the calculated prefix sum is checked against k, and if it satisfies the condition, it's counted.

Time Complexity:
O(m * n)
The code iterates through all m rows and n columns of the grid exactly once.

Space Complexity:
O(m * n)
A 2D prefix sum array of size (m+1) x (n+1) is allocated.

Optimization Notes:
This solution is optimal for counting submatrices starting at (0,0) with sum <= k. If the problem requires counting *any* submatrix (arbitrary top-left and bottom-right corners) with sum <= k, this solution is incorrect and not optimal as it only considers submatrices originating from (0,0).

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
