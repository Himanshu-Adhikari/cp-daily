# 📅 Daily CP Solutions — 2026-05-07

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Check If Subtree
**Platform:** GeeksforGeeks

Problem Insight:
The problem asks to determine if a second tree is structurally and value-wise identical to any subtree within a first tree.

Approach:
The solution recursively traverses the first tree (root1) to find a node whose subtree is identical to the second tree (root2). A helper function 'rec' performs a direct structural and value comparison of two subtrees.

Time Complexity:
O(N*M) where N is nodes in root1 and M is nodes in root2. In the worst case, every node in root1 triggers a full comparison with root2.

Space Complexity:
O(Height(root1) + Height(root2)) in the worst case. This is due to the recursion stack depth from traversing both trees.

Optimization Notes:
This approach is not optimal. It can be improved to O(N+M) using tree serialization to strings with null markers and then applying string searching algorithms like KMP, or by using tree hashing techniques.

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
The problem calculates for each index i a specific value related to prefix maximums and suffix minimums. This value represents the highest prefix maximum of any 'valid split point' k >= i, where a split at k is valid if max(nums[0..k]) > min(nums[k+1..n-1]). If no such k >= i exists, the value is max(nums[0..i]).

Approach:
The solution precomputes prefix maximums (pm) and suffix minimums (sn). It then iterates backwards to populate the result array. For each index i, if pm[i] is greater than sn[i+1], it means a valid split exists, so res[i] inherits the value from res[i+1]. Otherwise, res[i] is set to pm[i].

Time Complexity:
O(N)
Prefix maximums, suffix minimums, and the final result array are each computed in a single linear pass.

Space Complexity:
O(N)
Three auxiliary arrays (pm, sn, res) are used, each storing N elements.

Optimization Notes:
The solution is optimal in terms of time complexity, as it requires at least a linear scan to compute the necessary aggregates and the final result. The O(N) space complexity is also generally optimal for this approach, as the precomputed prefix maximums and suffix minimums arrays are needed for the backward pass of the result calculation.

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
