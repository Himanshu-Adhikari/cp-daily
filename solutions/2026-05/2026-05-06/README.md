# 📅 Daily CP Solutions — 2026-05-06

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Size Of Binary Tree
**Platform:** GeeksforGeeks

Problem Insight:
The problem is to determine the total number of nodes present in a given binary tree. It requires traversing all nodes to count them.

Approach:
The solution employs a recursive depth-first approach. It counts the current node (1) and then recursively sums the sizes of its left and right subtrees. A base case handles null nodes by returning 0.

Time Complexity:
O(N) where N is the number of nodes. Each node in the tree is visited exactly once to be counted.

Space Complexity:
O(H) where H is the height of the tree. This space is used by the recursion call stack, which can go as deep as the tree's height.

Optimization Notes:
The solution is optimal in terms of time complexity, as every node must be visited to be counted, making O(N) the lower bound. It is also optimal for space complexity in general, as the recursion stack depth is tied to the tree's height.

### 💻 Implementation
```cpp
class Solution {
  public:
    int getSize(Node* root) {
        if(!root)return 0;
        return 1+getSize(root->left)+getSize(root->right);
    }
};
```

## 🔹 Leetcode Rotating The Box
**Platform:** LeetCode

Problem Insight:
The problem requires simulating gravity on falling stones within a grid after a 90-degree clockwise rotation, with obstacles blocking stone movement. Gravity acts downwards in the rotated grid.

Approach:
The solution initializes a new grid with dimensions swapped for rotation. It iterates through each row of the original grid from right to left, simulating the effect of gravity in the rotated column. Stones fall to the lowest available spot or just above an obstacle, while obstacles stay fixed.

Time Complexity:
O(N*M)
The code iterates through each cell of the N x M input grid exactly once to populate the new M x N result grid.

Space Complexity:
O(M*N)
A new M x N grid is created to store the result, requiring space proportional to the input grid's size.

Optimization Notes:
The solution is optimal. It processes each cell once and requires creating a new grid of size M x N, making O(M*N) time and space unavoidable.

### 💻 Implementation
```py
class Solution:
    def rotateTheBox(self, g: List[List[str]]) -> List[List[str]]:
        n,m=len(g),len(g[0])
        res=[['.' for i in range(n)] for j in range(m)]
        for i in range(n):
            c=m-1
            for j in range(m-1,-1,-1):
                if(g[i][j]=='#'):
                    res[c][n-1-i]='#'
                    c-=1
                elif(g[i][j]=='*'):
                    res[j][n-1-i]='*'
                    c=j-1
        return res
```
