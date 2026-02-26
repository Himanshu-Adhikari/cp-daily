# 📅 Daily CP Solutions — 2026-02-26

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Isomorphic Strings
**Platform:** GeeksforGeeks

Problem Insight:
Determines if two strings are isomorphic, meaning a bijective (one-to-one and onto) mapping exists between their characters while preserving order. Both forward and backward mappings must be consistent.

Approach:
Iterate through both strings simultaneously. Maintain two maps: one for s1 to s2 character mappings and another for s2 to s1 mappings. For each character pair, establish new mappings if characters are unseen, or verify consistency with existing mappings. Return false immediately if any inconsistency is found.

Time Complexity:
O(n)
The code iterates through the strings once. Map operations (lookup, insertion) take O(log K) time, where K is the alphabet size, which is treated as a constant.

Space Complexity:
O(K)
Two maps are used to store character mappings. In the worst case, they store up to K entries each, where K is the size of the character set (e.g., 256 for ASCII).

Optimization Notes:
The solution is optimal in terms of time complexity, O(n), as all characters must be processed. Space complexity is O(K). Using arrays (e.g., char[256]) instead of maps could offer slightly better constant factors for time and space due to O(1) access and less overhead, but the overall Big-O remains the same.

### 💻 Implementation
```cpp
class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        map<char,char>m,a;
        int n=s1.size();
        for(int i=0;i<n;i++){
            if(!m.count(s1[i]) and !a.count(s2[i])){
                m[s1[i]]=s2[i];
                a[s2[i]]=s1[i];
            }
            else if(m.count(s1[i]) and a.count(s2[i]) and m[s1[i]]==s2[i] and a[s2[i]]==s1[i])continue;
            else return false;
        }
        return true;
    }
};
```

## 🔹 Leetcode 1404 Number-Of-Steps-To-Reduce-A-Number-In-Binary-Representation-To-One
**Platform:** LeetCode

Problem Insight:
This problem can be solved by simulating the operations on the binary string from right to left, handling carries. Each step (odd: add 1 then divide by 2; even: divide by 2) translates to specific changes in the binary representation.

Approach:
The solution processes the binary string from right to left (least significant to second most significant bit), maintaining a carry. If a digit plus carry is odd, it requires two operations (add 1, then divide by 2) and generates a carry. If it's even, it requires one operation (divide by 2) and updates the carry based on the bit's value and incoming carry. The final operations count includes any remaining carry that represents one last division step.

Time Complexity:
O(N) where N is the length of the binary string. The loop iterates N-1 times, performing constant time arithmetic operations in each iteration.

Space Complexity:
O(1). The solution uses a fixed number of integer variables, independent of the input string length.

Optimization Notes:
The solution is optimal. It processes each bit of the string exactly once to determine the number of steps, making it a linear time algorithm. No faster approach is possible as all bits may contribute to the total steps.

### 💻 Implementation
```py
class Solution:
    def numSteps(self, s: str) -> int:
        N = len(s)
        operations = 0
        carry = 0
        for i in range(N - 1, 0, -1):
            digit = int(s[i]) + carry
            if digit % 2 == 1:
                operations += 2
                carry = 1
            else:
                operations += 1

        return operations + carry
```
