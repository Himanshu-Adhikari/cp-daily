# 📅 Daily CP Solutions — 2026-02-24

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Longest-Span-With-Same-Sum-In-Two-Binary-Arrays
**Platform:** GeeksforGeeks

Problem Insight:
The problem is to find the longest common span [L, R] such that the sum of elements in a1 from L to R equals the sum in a2 from L to R. This is equivalent to finding the longest subarray with a sum of zero in the element-wise difference array (a1[i] - a2[i]).

Approach:
A new array is created where each element is the difference (a1[i] - a2[i]). Then, prefix sums of this difference array are computed. A map stores the first occurrence of each prefix sum, and when a prefix sum is encountered again, the length of the subarray between the current index and its first occurrence is calculated to find a zero-sum subarray.

Time Complexity:
O(N log N)
Creating the difference array takes O(N). Iterating through it and performing map operations (insertion, lookup in std::map) takes O(log K) for K distinct prefix sums, leading to O(N log N) total.

Space Complexity:
O(N)
A new difference array of size N is created, and the map can store up to N distinct prefix sums in the worst case.

Optimization Notes:
The solution is optimal in terms of space complexity. For time complexity, using an std::unordered_map instead of std::map would improve the average time complexity to O(N), which is the optimal average-case performance.

### 💻 Implementation
```cpp
class Solution {
  public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        int n=a1.size();
        int c=0,res=0;
        vector<int>b;
        for(int i=0;i<n;i++){
            b.push_back(a1[i]-a2[i]);
        }
        map<int,int>m;
        m[0]=-1;
        int sm=0;
        for(int i=0;i<n;i++){
            sm+=b[i];
            if(sm==0)res=max(res,i+1);
            if(m.count(sm))res=max(res,i-m[sm]);
            else m[sm]=i;
        }
        return res;
    }
};
```

## 🔹 Leetcode 1022 Sum-Of-Root-To-Leaf-Binary-Numbers
**Platform:** LeetCode

Problem Insight:
The task is to compute the sum of all binary numbers represented by paths from the root to each leaf node in a binary tree. Node values are either 0 or 1.

Approach:
The solution employs a depth-first search (DFS) traversal. It builds a binary string representation of the path as it descends the tree, and upon reaching a leaf node, converts this accumulated string into an integer value, which is then returned and summed up.

Time Complexity:
O(N^2)
String concatenation and the explicit binary string to integer conversion at each leaf node take time proportional to the current path length (up to N), and these operations occur for up to N nodes.

Space Complexity:
O(N)
The recursion stack depth can be up to N in the worst case (a skewed tree), and the accumulated binary string can also store up to N characters.

Optimization Notes:
The solution is not optimal. String manipulations and conversions are costly. It can be optimized by passing the current integer value (representing the binary number so far) down the tree, performing a left-shift and bitwise OR operation at each step, eliminating string overhead and achieving O(N) time complexity.

### 💻 Implementation
```py
class Solution:
    
    def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:
        def rec(s,r):
            if(not r):
                return 0
            if((not r.left) and (not r.right)):
                res=0
                if(r.val==1):
                    s+='1'
                else:
                    s+='0'
                n=len(s)
                for i in range(n-1,-1,-1):
                    if(s[i]=='1'):res+=(1<<(n-1-i))
                print(s,res)
                return res
            if(r.val==1):
                s+='1'
            else:
                s+='0'
            l=rec(s,r.left)
            r=rec(s,r.right)
            return l+r
        return rec("",root)
```
