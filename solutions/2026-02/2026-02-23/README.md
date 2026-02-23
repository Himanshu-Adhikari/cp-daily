# 📅 Daily CP Solutions — 2026-02-23

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Union Of Arrays With Duplicate
**Platform:** GeeksforGeeks

Problem Insight:
The problem requires finding all unique elements present in either of two given arrays, returning them in sorted order.

Approach:
A std::set is used to store elements from both input arrays. The set inherently handles uniqueness and maintains elements in sorted order. All elements from the first array are added, then all from the second, and finally the set's contents are converted to a vector.

Time Complexity:
O((N+M) log (N+M)).
Justification: Each of the N elements from the first array and M elements from the second array is inserted into a set, taking logarithmic time per insertion, where the log term depends on the current set size.

Space Complexity:
O(N+M).
Justification: The set stores up to N+M unique elements, and the returned vector also occupies space for these elements.

Optimization Notes:
This approach is optimal for its simplicity and robustness, leveraging the properties of std::set for uniqueness and sorted output. If the input arrays were guaranteed to be sorted, a two-pointer approach could achieve O(N+M) time complexity with O(1) auxiliary space (excluding the result vector).

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
The problem requires checking if every possible binary string of length k (totaling 2^k unique codes) exists as a substring within the input string s. It essentially asks for the count of distinct k-length substrings to equal 2^k.

Approach:
The solution generates all possible substrings of length k from the input string s. Each unique k-length substring is stored in a hash set. After processing all substrings, the size of the set is compared against 2^k.

Time Complexity:
O(N * K^2)
Justification: There are N-K+1 substrings. Each substring is constructed using repeated string concatenation in O(K^2) time and then added to the hash set in O(K) average time.

Space Complexity:
O(min(N, 2^K) * K)
Justification: The hash set stores at most min(N-K+1, 2^K) unique strings, each of length K.

Optimization Notes:
The current code builds substrings using inefficient repeated string concatenation, resulting in O(K^2) per substring. This can be improved to O(K) per substring by using Python's string slicing (s[i:i+k]), reducing total time to O(N*K). For binary strings, a more optimal solution uses bit manipulation (rolling hash or integer conversion) to process each substring in O(1) average time and store them in a boolean array or integer set, achieving O(N + 2^K) time complexity.

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
