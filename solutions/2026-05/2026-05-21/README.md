# 📅 Daily CP Solutions — 2026-05-21

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Check If All Bits Are Set
**Platform:** GeeksforGeeks

Problem Insight:
The problem aims to determine if all bits in the binary representation of a given non-negative integer are set to 1. This implies checking if the number is of the form 2^k - 1.

Approach:
The solution converts the integer to its binary string representation (excluding the "0b" prefix). It then iterates through each character of this binary string. If any character is '0', it immediately returns False; otherwise, if the loop completes, it returns True.

Time Complexity:
O(log N)
String conversion `bin(n)` takes O(log N) time and iterating through the string takes O(log N) time, where log N is the number of bits in N.

Space Complexity:
O(log N)
The binary string `s` stores the binary representation of N, requiring space proportional to the number of bits in N (log N).

Optimization Notes:
The current solution is not optimal. A bitwise approach can achieve O(1) time and O(1) space complexity. An integer n has all its bits set if and only if n is positive and n + 1 is a power of two. This can be checked by verifying if n > 0 and (n & (n + 1)) == 0.

CODE:
class Solution:
    def isBitSet(self, n):
        s=bin(n)[2::]
        for i in s:
            if(i=='0'):return False
        return True

### 💻 Implementation
```py
class Solution:
    def isBitSet(self, n):
        s=bin(n)[2::]
        for i in s:
            if(i=='0'):return False
        return True
```

## 🔹 Leetcode Find The Length Of The Common Longest Prefix
**Platform:** LeetCode

Problem Insight:
The goal is to find the maximum length of a common digit prefix that exists between any number from arr1 and any number from arr2.

Approach:
Build a Trie (prefix tree) by inserting all numbers from arr1, digit by digit. Then, for each number in arr2, traverse the constructed Trie to find the longest matching prefix, updating the overall maximum length found.

Time Complexity:
O(S1 + S2), where S1 is the total count of digits in all numbers in arr1 and S2 is the total count of digits in all numbers in arr2. This is because each digit from both arrays is processed at most once.

Space Complexity:
O(S1), where S1 is the total count of digits in all numbers in arr1. The Trie stores nodes corresponding to all distinct prefixes of numbers from arr1.

Optimization Notes:
This solution is optimal as it requires processing all digits of numbers in both arrays at least once. A minor constant factor optimization could be achieved by using a fixed-size array (e.g., node* children[10]) instead of std::map for child pointers in the Trie nodes, given the small and fixed alphabet size (digits 0-9).

### 💻 Implementation
```cpp
class node {
public:
    map<int, node*> m;

    void in(int c, node* t) {
        string s = to_string(c);
        for (auto d : s) {
            if (t->m.count(d - '0')) {
                t = t->m[d - '0'];
            } else {
                t->m[d - '0'] = new node();
                t = t->m[d - '0'];
            }
        }
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        node* rt = new node();
        node* t;
        for (auto c : arr1) {
            t = rt;
            t->in(c, t);
        }

        int res = 0;
        for (auto d : arr2) {
            t = rt;
            string s = to_string(d);
            int curr = 0;

            for (auto c : s) {
                if (t->m.count(c - '0')) {
                    curr++;
                    t = t->m[c - '0'];
                } else break;
            }
            res = max(res, curr);
        }

        return res;
    }
};

```
