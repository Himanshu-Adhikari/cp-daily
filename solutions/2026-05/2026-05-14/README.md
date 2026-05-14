# 📅 Daily CP Solutions — 2026-05-14

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Search For Subarray
**Platform:** GeeksforGeeks

Problem Insight:
The problem asks to find all starting indices where a given pattern vector 'b' appears as a sub-vector within a text vector 'a'. This is a classical pattern searching problem adapted for integer vectors.

Approach:
The solution implements the Knuth-Morris-Pratt (KMP) algorithm. It first precomputes a Longest Proper Prefix Suffix (LPS) array for the pattern vector 'b' to optimize shifts. Then, it uses this LPS array to efficiently match 'b' within 'a', avoiding re-comparison of characters that are known to match.

Time Complexity:
O(n + m)
The LPS array computation takes O(m) time, and the search phase takes O(n) time, where 'n' is the size of 'a' and 'm' is the size of 'b'.

Space Complexity:
O(m + k)
The 'lp' array uses O(m) space, and the 'res' vector stores 'k' occurrences, which can be up to O(n) in the worst case.

Optimization Notes:
The KMP algorithm is an optimal solution for this problem in terms of time complexity, achieving linear time (O(n+m)). No further asymptotic time complexity improvements are possible. The current implementation is efficient and standard for KMP.

### 💻 Implementation
```cpp
class Solution {
  public:
    vector<int> search(vector<int> &a, vector<int> &b) {
        int m=b.size();
        vector<int>lp(m,0);
        int i=1,j=0;
        int n=a.size();
        while(i<m){
            if(b[i]==b[j]){
                lp[i++]=++j;
            }
            else{
                if(j)j=lp[j-1];
                else i++;
            }
        }
        i=0,j=0;
        vector<int>res;
        while(i<n){
            if(a[i]==b[j]){
                i++,j++;
                if(j==m){res.push_back(i-j);j=lp[j-1];}
            }
            else{
                if(j)j=lp[j-1];
                else i++;
            }
        }
        return res;
        
    }
};
```

## 🔹 Leetcode Check If Array Is Good
**Platform:** LeetCode

Problem Insight:
The problem defines a "good" list as one where numbers 1 through N-1 appear once, and N appears twice, with N being len(nums)-1.

Approach:
The solution uses a frequency map to count occurrences of each number in the input list. It then verifies that numbers 1 to N-1 each have a count of 1, and N has a count of 2.

Time Complexity:
O(L) where L is the length of the input list. Building the frequency map takes O(L) time, and checking counts takes O(N) time (N is L-1).

Space Complexity:
O(L) where L is the length of the input list. The frequency map (Counter) stores up to L distinct numbers.

Optimization Notes:
This solution is optimal in terms of time complexity, as processing all elements is a lower bound. Its space complexity is also optimal for storing arbitrary number frequencies.

### 💻 Implementation
```py
class Solution:
    def isGood(self, nums: List[int]) -> bool:
        a=Counter(nums)
        n=len(nums)-1
        for i in range(1,n):
            if(not a[i]): return False
        return a[n]==2

```
