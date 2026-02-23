# 📅 Daily CP Solutions — 2026-02-08

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Maximum-Product-Subarray
**Platform:** GeeksforGeeks

Problem Insight:
The maximum product subarray can involve negative numbers, where an even count of negatives yields a positive product. We must track both the maximum and minimum products ending at the current position.

Approach:
Iterate through the array, maintaining the current maximum and minimum products ending at the present index. If the current number is negative, swap the max and min product trackers to account for the sign change before updating them. Update the overall maximum product found so far at each step.

Time Complexity:
O(N)
The algorithm performs a single pass through the array. The initial max_element call also takes O(N).

Space Complexity:
O(1)
Only a fixed number of auxiliary variables are used regardless of input size.

Optimization Notes:
It is optimal. The solution processes each element once, achieving linear time complexity, which is the lower bound for this problem. It also uses constant extra space.

### 💻 Implementation
```cpp
class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        int res=*max_element(begin(arr),end(arr));
        int maxi=arr[0];
        int mini=arr[0];
        for(int i=1;i<arr.size();i++){
            if(arr[i]<0)
                swap(maxi,mini);
            maxi=max(arr[i],maxi*arr[i]);
            mini=min(arr[i],mini*arr[i]);
            res=max(res,maxi);
        }
        return res;
    }
};
```

## 🔹 Leetcode Balanced-Binary-Tree
**Platform:** LeetCode

Problem Insight:
A binary tree is balanced if for every node, the heights of its left and right subtrees differ by at most 1. An empty tree is balanced.

Approach:
The solution uses a post-order depth-first search (DFS) that returns both a boolean indicating if the subtree is balanced and an integer representing its height. It recursively checks balance and height for children, then combines these results for the current node.

Time Complexity:
O(N) where N is the number of nodes in the tree. Each node is visited exactly once during the single DFS traversal.

Space Complexity:
O(H) where H is the height of the tree. This accounts for the recursion stack depth, which can be O(N) in the worst case (skewed tree).

Optimization Notes:
The solution is optimal. It avoids redundant calculations by returning both balance status and height in a single pass, which is more efficient than a two-pass approach (where one pass calculates heights and a second pass checks balance).

### 💻 Implementation
```py
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def dfs(root):
            if not root:
                return [True, 0]
            left_balanced, left_height = dfs(root.left)
            right_balanced, right_height = dfs(root.right)
            is_balanced = left_balanced and right_balanced and abs(left_height - right_height) <= 1
            return [is_balanced, 1 + max(left_height, right_height)]
        return dfs(root)[0]
```
