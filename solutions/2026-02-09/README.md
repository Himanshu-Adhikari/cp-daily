# 📅 Daily CP Solutions — 2026-02-09

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Find Kth Rotation
**Platform:** GeeksforGeeks

Problem Insight:
The problem aims to find the number of rotations applied to a sorted array, which is equivalent to finding the index of its minimum element.

Approach:
The solution first identifies the minimum value within the array using a linear scan. Subsequently, it iterates through the array again to locate the first occurrence of this minimum value and returns its index as the rotation count.

Time Complexity:
O(N)
Finding the minimum element with min_element takes O(N), and then iterating through the array to find its index also takes O(N) in the worst case.

Space Complexity:
O(1)
The solution uses only a few constant extra variables, independent of the input array size.

Optimization Notes:
It is not optimal. This problem can be solved more efficiently in O(log N) time using a binary search approach to locate the minimum element (the pivot point) in the rotated sorted array. The current solution's linear scan makes it less efficient for larger inputs.

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
The goal is to transform an arbitrary Binary Search Tree (BST) into a height-balanced BST to ensure efficient O(log N) operations.

Approach:
The solution first flattens the BST into a sorted list of nodes using an in-order traversal. It then recursively builds a balanced BST from this sorted list by picking the middle element as the root, and then recursively building its left and right subtrees from the remaining parts of the list.

Time Complexity:
O(N)
Justification: O(N) for in-order traversal to populate the vector and O(N) for building the new tree structure from the vector.

Space Complexity:
O(N)
Justification: O(N) auxiliary space is used to store all TreeNode pointers in the vector 'v', plus O(N) for the recursion stack in the worst case for the initial traversal.

Optimization Notes:
The solution is optimal in time complexity O(N) as all nodes must be processed. It is not space optimal compared to algorithms like the Day-Stout-Warren algorithm, which can balance a BST in-place using O(1) auxiliary space (excluding recursion stack for the initial traversal). However, for reconstructing the tree by re-parenting, O(N) space for the node list is a common and acceptable approach.

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
