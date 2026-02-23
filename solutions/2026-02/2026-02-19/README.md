# 📅 Daily CP Solutions — 2026-02-19

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Missing Elements In Range
**Platform:** GeeksforGeeks

Problem Insight:
Find all integers in a specified range [low, high] that are not present in a given input array.

Approach:
The solution first inserts all elements from the input array into a set for quick existence checks. Then, it iterates from 'low' to 'high' and adds any number not found in the set to the result list.

Time Complexity:
O(N log N + R log N) where N is array size and R is range size (high - low + 1). Set construction is O(N log N) and R lookups are O(R log N).

Space Complexity:
O(N + R) where N is array size and R is range size. The set stores N elements and the result vector stores up to R elements.

Optimization Notes:
It is not optimal. Using a hash set (std::unordered_set) instead of std::set would reduce the average time complexity to O(N + R) due to O(1) average time lookups.

CODE:
class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        vector<int>res;
        set<int>a(begin(arr),end(arr));
        for(int i=low;i<=high;i++)if(!a.count(i))res.push_back(i);
        return res;
    }
};

### 💻 Implementation
```cpp
class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        vector<int>res;
        set<int>a(begin(arr),end(arr));
        for(int i=low;i<=high;i++)if(!a.count(i))res.push_back(i);
        return res;
    }
};
```

## 🔹 Leetcode Count Binary Substrings
**Platform:** LeetCode

Problem Insight:
The problem counts substrings where all 0s are grouped, all 1s are grouped, and the count of 0s equals the count of 1s. This implies looking for adjacent blocks of identical characters.

Approach:
The solution iterates through the string, grouping consecutive identical characters and counting their lengths. It maintains counts of the current and previous groups. When the character changes, it adds the minimum of the current and previous group lengths to the total result.

Time Complexity:
O(N)
The solution iterates through the input string exactly once, performing constant time operations per character.

Space Complexity:
O(1)
The solution uses a fixed number of variables regardless of the input string's length.

Optimization Notes:
This solution is optimal. It processes the string in a single pass (O(N) time) and uses only a constant amount of extra space (O(1) space), which is the most efficient possible for this problem.

### 💻 Implementation
```py
class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        res=0
        cur,prv=0,0
        pr=-1
        for i in s:
            if(pr==-1 or i==pr):
                cur+=1
            else:
                res+=min(cur,prv)
                prv=cur
                cur=1
            pr=i
        res+=min(cur,prv)
        return res
```
