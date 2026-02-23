# 📅 Daily CP Solutions — 2026-02-09

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Find Kth Rotation
**Platform:** GeeksforGeeks

Problem Insight:
The number of rotations in a sorted array is determined by the index of its minimum element. Finding this index gives the rotation count.

Approach:
The solution first finds the absolute minimum value present in the array. Then, it linearly iterates through the array to locate the first occurrence of this minimum value and returns its index.

Time Complexity:
O(N)
Finding the minimum element using *min_element* takes O(N), and the subsequent linear search for its index also takes O(N).

Space Complexity:
O(1)
Only a constant amount of extra space is used for variables, regardless of the input array size.

Optimization Notes:
The solution is not optimal. For a rotated sorted array, the index of the minimum element can be found in O(logN) time using a modified binary search, which is much faster than the current O(N) approach for larger arrays.

### 💻 Implementation
```cpp
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int mn=*min_element(begin(arr),end(arr));
        int n=arr.size();
        for(int i=0;i<n;i++)if(arr[i]==mn)return i;
        return n;
    }
};

```

## 🔹 Leetcode Balance-A-Binary-Search-Tree
**Platform:** LeetCode

Problem Insight:
Balancing a BST means rearranging its nodes to minimize height while preserving the BST property. An in-order traversal provides nodes in a sorted sequence, ideal for reconstructing a balanced tree.

Approach:
The solution first flattens the input BST into a sorted list of nodes using an in-order traversal. Then, it recursively builds a new balanced BST from this sorted list by choosing the middle element as the root, and recursively constructing the left and right subtrees from the remaining halves.

Time Complexity:
O(N)
An in-order traversal takes O(N) time, and constructing the new tree from the sorted list also takes O(N) time as each node is processed once.

Space Complexity:
O(N)
A vector stores N TreeNode pointers. The recursion stack for the initial in-order traversal can be O(N) in the worst case for a skewed tree.

Optimization Notes:
This solution is optimal for time complexity O(N) as all nodes must be visited. It uses O(N) auxiliary space, which is generally considered optimal for this problem given the need to effectively reorder all nodes. While more complex in-place balancing algorithms exist, they typically require node-specific metadata or more intricate pointer manipulation.

CODE:
class Solution {
public:
    vector<TreeNode*> v;
    int n;
    void rec(TreeNode* root) {
        if (!root)
            return;
        rec(root->left);
        v.push_back(root);
        rec(root->right);
    }
    TreeNode* bld(int l, int r) {
        if (l >r)
            return NULL;
        int m=l+(r-l)/2; 
        TreeNode* res = v[m];
        res->left = bld(l, m-1);
        res->right = bld(m + 1, r);
        return res;
    }
    TreeNode* balanceBST(TreeNode* root) {
        rec(root);
        n = v.size();
        return bld(0, n - 1);
    }
};

### 💻 Implementation
```cpp
class Solution {
public:
    vector<TreeNode*> v;
    int n;
    void rec(TreeNode* root) {
        if (!root)
            return;
        rec(root->left);
        v.push_back(root);
        rec(root->right);
    }
    TreeNode* bld(int l, int r) {
        if (l >r)
            return NULL;
        int m=l+(r-l)/2; 
        TreeNode* res = v[m];
        res->left = bld(l, m-1);
        res->right = bld(m + 1, r);
        return res;
    }
    TreeNode* balanceBST(TreeNode* root) {
        rec(root);
        n = v.size();
        return bld(0, n - 1);
    }
};
```
