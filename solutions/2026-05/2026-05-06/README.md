# 📅 Daily CP Solutions — 2026-05-06

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Size Of Binary Tree
**Platform:** GeeksforGeeks

Problem Insight:
The problem is to determine the total number of nodes present in a given binary tree.
It counts nodes by summing itself plus its left and right subtree counts.

Approach:
The solution uses a recursive depth-first approach. It returns 0 for a null node, and for a non-null node, it returns 1 plus the size of its left subtree and the size of its right subtree.

Time Complexity:
O(N) where N is the number of nodes. Each node in the tree is visited exactly once to count itself.

Space Complexity:
O(H) where H is the height of the tree. This is due to the recursion stack depth, which can be O(N) in the worst case (a skewed tree).

Optimization Notes:
This solution is optimal in time complexity because every node must be visited at least once to be counted, making O(N) unavoidable. While space complexity can be O(N) for skewed trees, this is typical for recursive tree traversals. An iterative approach would also use O(N) space in the worst case for an explicit stack.

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
This problem combines a 90-degree clockwise grid rotation with a gravity simulation, where stones fall to the bottom of their new columns until an obstacle or another stone stops them.

Approach:
The solution creates a new grid with rotated dimensions. It iterates through the original grid row by row, processing elements from right to left within each row. This allows it to simulate gravity by tracking the lowest available position for stones in the new columns, adjusting this position whenever an obstacle is encountered.

Time Complexity:
O(N*M)
Each cell of the N x M input grid is visited and processed exactly once with constant time operations.

Space Complexity:
O(N*M)
A new M x N grid is allocated to store the rotated and gravity-affected box, proportional to the input size.

Optimization Notes:
The solution is optimal. It is impossible to solve this problem without reading all input cells and producing an output grid of similar size, thus the O(N*M) time and space complexities are minimal requirements.

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
