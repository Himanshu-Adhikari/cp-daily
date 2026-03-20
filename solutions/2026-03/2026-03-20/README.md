# 📅 Daily CP Solutions — 2026-03-20

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Predecessor-And-Successor
**Platform:** GeeksforGeeks

Problem Insight:
The problem requires finding the inorder predecessor (largest node with data less than key) and successor (smallest node with data greater than key) for a given key in a BST.

Approach:
The solution performs an inorder traversal of the BST. It uses global pointers to store the result. The predecessor is continuously updated with any node whose data is less than the key, ensuring the last one found is the largest. The successor is updated only once with the first node found whose data is greater than the key.

Time Complexity:
O(N) where N is the number of nodes in the tree. The solution performs a complete inorder traversal, visiting every node.

Space Complexity:
O(H) where H is the height of the tree. This is due to the recursion stack depth. In the worst case (skewed tree), H can be N.

Optimization Notes:
The solution is not optimal for a Binary Search Tree. For a BST, predecessor and successor can be found in O(H) time by leveraging the BST property and traversing a single path from the root, rather than a full O(N) traversal. This can be significantly faster, especially for balanced trees where H is log N.

### 💻 Implementation
```cpp

class Solution {
  public:
    vector<Node*>res={NULL,NULL};
    void rec(Node* root, int key){
        if(!root)return;
        rec(root->left,key);
        if(root->data<key)res[0]=root;
        if(root->data>key and res[1]==NULL)res[1]=root;
        rec(root->right,key);
    }
    vector<Node*> findPreSuc(Node* root, int key) {
        rec(root,key);
        return res;
    }
};
```

## 🔹 Leetcode Minimum-Absolute-Difference-In-Sliding-Submatrix
**Platform:** LeetCode

Problem Insight:
The task is to find the minimum absolute difference between any two distinct elements within every k x k subgrid in a given 2D grid. The output is a new grid containing these minimum differences.

Approach:
The solution iterates through all possible top-left corners of k x k subgrids. For each subgrid, it collects all its elements into a set to ensure uniqueness and automatic sorting. Then, it iterates through the sorted unique elements in the set to find the minimum absolute difference between any two consecutive elements.

Time Complexity:
O((m-k+1) * (n-k+1) * k*k * log(k*k))
Each of the (m-k+1)*(n-k+1) subgrids involves inserting k*k elements into a set (each insertion taking O(log(k*k))) and then iterating through the set (O(k*k)).

Space Complexity:
O((m-k+1) * (n-k+1) + k*k)
The result matrix occupies O((m-k+1)*(n-k+1)) space, and the set 'a' temporarily stores up to k*k elements.

Optimization Notes:
The current solution is not optimal. It reconstructs the set of elements for each k x k subgrid from scratch. A more efficient approach would utilize a 2D sliding window where elements are added and removed from a data structure (like a multiset) as the window slides. This allows updating the minimum absolute difference in O(k log(k*k)) per window movement, improving the overall time complexity significantly.

### 💻 Implementation
```cpp
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>res(m-k+1,vector<int>(n-k+1));
                set<int>a;
        if(k==1)return res;
        for(int i=0;i<m-k+1;i++){
            for(int j=0;j<n-k+1;j++){
                a.clear();
                for(int x=0;x<k && (i+x)<m;x++){
                    for(int y=0;y<k && (j+y)<n;y++){
                        a.insert(grid[x+i][y+j]);
                        cout<<grid[x+i][y+j]<<" ";
                    }
                }
                cout<<endl;
                int t=0,pr,cr=INT_MAX;
                for(auto c:a){
                   if(t==0)t=1;
                   else cr=min(cr,abs(pr-c));
                   pr=c;
                }
                if(cr==INT_MAX)res[i][j]=0;
                else res[i][j]=cr;
            }
        }
        return res;
    }
};
```
