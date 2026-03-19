# 📅 Daily CP Solutions — 2026-03-19

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Largest Bst
**Platform:** GeeksforGeeks

Problem Insight:
This problem requires determining if a subtree is a BST while simultaneously finding the largest BST size. A post-order traversal (bottom-up approach) is suitable for this.

Approach:
The solution uses a recursive post-order traversal. For each node, it recursively gets information (largest BST size, is_BST flag, min_val, max_val) from its children. Based on this information and the current node's value, it determines if the current subtree is a BST and updates the overall largest BST size.

Time Complexity:
O(N)
Each node is visited exactly once, and constant time operations are performed at each node.

Space Complexity:
O(H)
The space complexity is dominated by the recursion stack depth, which is proportional to the height of the tree (H).

Optimization Notes:
The solution is optimal. It processes each node exactly once, which is the minimum required for traversing the tree, and stores minimal necessary information.

### 💻 Implementation
```cpp
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a 
    vector<int> solve(Node* root){
        if(root==NULL){
            return {0, 1, INT_MAX, INT_MIN};
        }
        
        if(root->left==NULL && root->right==NULL){
            return {1, 1, root->data, root->data};
        }
        
        vector<int>lft=solve(root->left);
        vector<int>rgt=solve(root->right);
        
        int lftCnt=lft[0], lftAns=lft[1], lftMax=lft[3], lftMin=lft[2];
        int rgtCnt=rgt[0], rgtAns=rgt[1], rgtMax=rgt[3], rgtMin=rgt[2];
        
        if(lftAns==1 && rgtAns==1 && root->data>lftMax && root->data<rgtMin){
            return {lftCnt+rgtCnt+1, 1, min(root->data, lftMin), max(root->data, rgtMax)};
        }else{
            return {max(lftCnt, rgtCnt), 0, 0, 0};
        }
        
    }
    
    int largestBst(Node *root)
    {
    	//Your code here
    	return solve(root)[0];
    }
};
```

## 🔹 Leetcode Count-Submatrices-With-Equal-Frequency-Of-X-And-Y
**Platform:** LeetCode

Problem Insight:
The problem counts submatrices that start at grid[0][0] and extend to grid[i][j], where the total count of 'X' characters equals the total count of 'Y' characters, and both counts are greater than zero.

Approach:
Two 2D prefix sum arrays are precomputed: one to track 'X' counts and another for 'Y' counts. The code then iterates through all possible bottom-right corners (i,j) of submatrices anchored at (0,0), checking if the precomputed 'X' count equals the 'Y' count and is non-zero.

Time Complexity:
O(N*M)
Two passes over the N x M grid are performed, each involving constant time operations.

Space Complexity:
O(N*M)
A 3D array of size N x M x 2 is used to store the prefix sums for 'X' and 'Y' counts.

Optimization Notes:
The solution is optimal for the specific problem it solves (counting submatrices anchored at the top-left corner (0,0)). Every cell must be visited to compute its prefix sum and check the condition, making O(N*M) the best possible time complexity. Similarly, storing the N*M prefix sums requires O(N*M) space.

### 💻 Implementation
```cpp
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int a[1001][1001][2]={0};
        int n=grid.size(),m=grid[0].size(),res=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                a[i][j][0]=a[i-1][j][0]+a[i][j-1][0]+(grid[i-1][j-1]=='X')-a[i-1][j-1][0];
                a[i][j][1]=a[i-1][j][1]+a[i][j-1][1]+(grid[i-1][j-1]=='Y')-a[i-1][j-1][1];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                res=res+(a[i][j][0] && a[i][j][0]==a[i][j][1]);
            }
        }
        return res;
    }
};
```
