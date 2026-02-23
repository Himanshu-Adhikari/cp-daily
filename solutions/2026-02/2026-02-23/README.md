# 📅 Daily CP Solutions — 2026-02-23

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Union Of Arrays With Duplicate
**Platform:** GeeksforGeeks

Problem Insight:
The problem aims to find the union of two integer arrays, meaning all distinct elements present in either array, typically returned in sorted order.

Approach:
The solution uses a standard library set. It inserts all elements from the first array into the set, then iterates through the second array and inserts its elements into the same set. Finally, it converts the set into a vector for the result.

Time Complexity:
O((N+M) log (N+M))
Each of the N+M elements is inserted into a set, with each insertion taking O(log K) time where K is the current set size.

Space Complexity:
O(N+M)
The set stores up to N+M unique elements, and the resulting vector also stores up to N+M elements.

Optimization Notes:
The solution is correct but not optimal if the input arrays are already sorted. A two-pointer approach could achieve O(N+M) time complexity by iterating through both sorted arrays simultaneously, avoiding the logarithmic factor from set operations.

### 💻 Implementation
```cpp
class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        set<int>h(a.begin(),a.end());
        for(int j:b)h.insert(j);
        return vector<int>(begin(h),end(h));
    }
};

```

## 🔹 Leetcode Check-If-A-String-Contains-All-Binary-Codes-Of-Size-K
**Platform:** LeetCode

Problem Insight:
The problem checks if every possible binary string of length k is present as a substring within s.

Approach:
The solution extracts all substrings of length k, adds them to a hash set, and then verifies if the set's size equals 2^k.

Time Complexity:
O(n * k^2)
The outer loop runs n-k+1 times. Building each k-length substring using repeated string concatenation takes O(k^2), and set insertion takes O(k).

Space Complexity:
O(2^k * k)
The set stores at most 2^k unique substrings, each of length k.

Optimization Notes:
The solution is not optimal. Using string slicing s[i:i+k] to extract substrings would reduce the time complexity for substring creation to O(k), making the total O(n*k). A more advanced rolling hash approach could achieve O(n) by representing substrings as integers and updating them in O(1), leading to O(n) total time assuming O(1) set operations for integers.

### 💻 Implementation
```py
class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        res=0
        st=set()
        n=len(s)
        for i in range(n-k+1):
            t=""
            for j in range(i,i+k):
                t+=s[j]
            st.add(t)
        return len(st)==(1<<k)
```
