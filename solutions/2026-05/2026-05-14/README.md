# 📅 Daily CP Solutions — 2026-05-14

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Search For Subarray
**Platform:** GeeksforGeeks

Problem Insight:
The problem is to find all occurrences of a given pattern (vector b) within a given text (vector a). This is a classic string matching problem.

Approach:
The solution uses the Knuth-Morris-Pratt (KMP) algorithm. It first preprocesses the pattern to build a Longest Proper Prefix Suffix (LPS) array, which guides efficient pattern shifting upon mismatches. Then, it iterates through the text, comparing characters and utilizing the LPS array to avoid redundant comparisons and find all pattern occurrences.

Time Complexity:
O(n + m) where n is the length of text a and m is the length of pattern b. Building the LPS array takes O(m) and searching the text takes O(n).

Space Complexity:
O(n + m) where n is the length of text a and m is the length of pattern b. This accounts for the LPS array (O(m)) and the result vector which can store up to O(n) occurrences.

Optimization Notes:
This solution implements the KMP algorithm, which is asymptotically optimal for string matching problems with a time complexity of O(N + M). No significant algorithmic improvements are possible for general cases.

CODE:
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
A "good" array of length M must contain numbers 1 to (M-2) exactly once, and the number (M-1) exactly twice. The array should not contain any other numbers.

Approach:
The length of the input array is used to determine the expected largest number, N = length - 1. A frequency map (Counter) is used to count occurrences of all numbers in the input. The solution then checks if numbers from 1 to N-1 are present (at least once), and finally verifies if N appears exactly twice.

Time Complexity:
O(M), where M is the length of nums. Building the Counter takes O(M) time, and the subsequent loop runs up to N-1 times (where N=M-1), contributing O(M) to the total.

Space Complexity:
O(M), where M is the length of nums. The Counter stores frequency for at most M distinct elements found in the input array.

Optimization Notes:
The solution is not fully correct. While it uses an efficient O(M) time and O(M) space approach, the check `if(not a[i])` only verifies that numbers from 1 to `n-1` are present *at least once*, not *exactly once*. If any number in this range appears more than once, the current solution would incorrectly pass that check. A correct implementation needs to verify `if a[i] != 1` for `i` in `range(1, n)` to ensure exact counts.

CODE:

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
