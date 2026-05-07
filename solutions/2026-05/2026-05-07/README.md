# 📅 Daily CP Solutions — 2026-05-07

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Check If Subtree
**Platform:** GeeksforGeeks

Problem Insight:
To determine if one tree is a subtree of another, we must check for identity at every node in the larger tree. This involves recursively comparing structures from potential match points.

Approach:
The algorithm recursively traverses the larger tree (root1). At each node in root1, it checks if the subtree rooted at that node is identical to root2 using a helper function. If no match is found, it continues searching in root1's left and right subtrees.

Time Complexity:
O(N * M)
In the worst case, for each of N nodes in root1, the helper function might compare up to M nodes of root2.

Space Complexity:
O(H1 + H2)
The maximum depth of the recursion stack is the sum of the heights of root1 and root2 in the worst case.

Optimization Notes:
The solution is not optimal. It can be improved to O(N + M) time complexity. This can be achieved by serializing both trees into strings and then using string matching algorithms like KMP, or by employing tree hashing techniques. The current approach performs redundant subtree comparisons.

### 💻 Implementation
```cpp
class Solution {
  public:
    bool rec(Node*r,Node*s){
        if(!r and !s)return true;
        if(!r or !s or s->data != r->data)return false;
        return rec(r->right,s->right) && rec(r->left,s->left);
    }
    bool isSubTree(Node *root1, Node *root2) {
        if(!root1)return false;
        if(root1->data==root2->data and rec(root1,root2))return true;
        return isSubTree(root1->left,root2) || isSubTree(root1->right,root2);
    }
};
```

## 🔹 Leetcode Jump Game Ix
**Platform:** LeetCode

Problem Insight:
The problem defines each element res[i] based on a condition involving prefix maximums, suffix minimums, and the value of res[i+1]. The last element is a special base case.

Approach:
The solution precomputes prefix maximums and suffix minimums in two linear passes. It then initializes the last result element and iteratively computes the remaining results backward using the precomputed arrays and the conditional logic.

Time Complexity:
O(n)
Justification: The solution involves three separate linear passes over the array of size n.

Space Complexity:
O(n)
Justification: Three auxiliary arrays (for prefix maximums, suffix minimums, and the result) each of size n are used.

Optimization Notes:
The solution is optimal in terms of both time and space complexity. Time is O(n) because all elements must be processed, and space is O(n) because precomputing prefix maximums and suffix minimums is necessary to achieve O(n) time complexity.

### 💻 Implementation
```py
class Solution:
    def maxValue(self, nums: List[int]) -> List[int]:
        mx=-1
        n=len(nums)
        pm=[0]*n
        sn=[0]*n
        sn[-1]=nums[-1]
        pm[0]=nums[0]
        for i in range(n-2,-1,-1):
            sn[i]=min(sn[i+1],nums[i])
        for i in range(1,n):
            pm[i]=max(nums[i],pm[i-1])
        res=nums[::]
        res[-1]=pm[-1]
        for i in range(n-2,-1,-1):
            if(pm[i]>sn[i+1]):
                res[i]=res[i+1]
            else:
                res[i]=pm[i]
        return res
```
