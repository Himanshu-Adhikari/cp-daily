# 📅 Daily CP Solutions — 2026-03-04

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Max-Xor-Subarray-Of-Size-K
**Platform:** GeeksforGeeks

Problem Insight:
This problem asks us to find the maximum XOR sum among all contiguous subarrays of a given fixed length K.

Approach:
The solution uses a sliding window of fixed size K. It maintains the XOR sum of the current window, updating the maximum result when the window reaches size K. The window slides by XORing out the leftmost element and XORing in the new rightmost element.

Time Complexity:
O(N)
The code iterates through the array once using a single loop, performing constant time operations within each iteration.

Space Complexity:
O(1)
Only a few variables are used to store array size, result, and window pointers, consuming constant extra space.

Optimization Notes:
This solution is optimal. It processes each element of the array a constant number of times, resulting in linear time complexity. Further algorithmic improvements are not possible as all subarrays of length K must be implicitly or explicitly considered.

### 💻 Implementation
```cpp
class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        int n=arr.size();
        int res=0;
        for(int i=0,j=0,c=0;i<n;i++){
            c^=arr[i];
            if(i-j+1==k){res=max(res,c),c^=arr[j++];}
        }
        return res;
    }
};
```

## 🔹 Leetcode Special-Positions-In-A-Binary-Matrix
**Platform:** LeetCode

Problem Insight:
The problem asks to count positions (i, j) where mat[i][j] is 1, and this 1 is the only 1 in its row and the only 1 in its column.

Approach:
First, iterate through the matrix to count the total number of 1s in each row and each column, storing these counts in auxiliary arrays. Second, iterate through the matrix again. For each cell (i, j) that contains a 1, check if its corresponding row count and column count are both exactly one. If so, it's a special position.

Time Complexity:
O(N*M)
Two passes over the N x M matrix are performed, each taking O(N*M) time.

Space Complexity:
O(N + M)
Two auxiliary arrays are used to store row counts (size N) and column counts (size M).

Optimization Notes:
This solution is optimal. It requires visiting every cell in the matrix at least once to determine its value, leading to an O(N*M) time complexity, which cannot be improved for an N x M matrix. The space complexity O(N+M) is also efficient for storing row and column aggregates.

### 💻 Implementation
```py
class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        n,m=len(mat),len(mat[0])
        a,b=[0]*n,[0]*m
        for i in range(n):
            for j in range(m):
                if(mat[i][j]):
                    a[i]+=1
                    b[j]+=1
        res=0
        for i in range(n):
         for  j in range(m):
            if(mat[i][j] and a[i]==1 and b[j]==1):res+=1 
        return res
```
