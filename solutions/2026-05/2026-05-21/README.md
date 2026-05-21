# 📅 Daily CP Solutions — 2026-05-21

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Check If All Bits Are Set
**Platform:** GeeksforGeeks

Problem Insight:
The problem checks if all bits in the binary representation of a non-negative integer are set to '1'. This means the number must be of the form 2^k - 1 for some k >= 0.

Approach:
The solution converts the integer to its binary string representation. It then iterates through this string (after removing the "0b" prefix). If it encounters any '0' character, it immediately returns False; otherwise, if all characters are '1', it returns True.

Time Complexity:
O(log n) because converting to binary string and iterating it takes time proportional to the number of bits in n, which is log n.

Space Complexity:
O(log n) because the binary string representation of n is stored, which has a length proportional to log n.

Optimization Notes:
The solution is not optimal. It uses string conversion and iteration, which is generally slower than bitwise operations. A more efficient O(1) time and O(1) space solution using bit manipulation exists. A number N has all bits set if N is positive and (N AND (N + 1)) evaluates to 0.

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
The core problem is to find the maximum length of a common prefix between the string representations of any number from two given arrays. A Trie (prefix tree) is well-suited for efficient prefix matching.

Approach:
First, a Trie is constructed by inserting the string representation of each number from arr1. Then, for each number in arr2, its string representation is traversed through the constructed Trie to find the longest prefix that exists in the Trie. The maximum length found across all numbers in arr2 is the final result.

Time Complexity:
O((N + M) * L) where N is arr1.size(), M is arr2.size(), and L is the maximum number of digits in any integer. This is because each number (N from arr1, M from arr2) is converted to string and its digits are processed (inserted or searched) in the Trie, taking O(L) time per number.

Space Complexity:
O(N * L) because in the worst case, the Trie stores approximately N * L nodes, representing all digits of all numbers in arr1. Each node uses a map for children pointers, which adds a constant factor.

Optimization Notes:
The solution is optimal for this problem. Using a Trie is the standard and most efficient approach for prefix matching on string data. The constant factor for converting integers to strings and using a map for Trie children could be slightly reduced with character arrays or direct modulo/division for digits and fixed-size arrays for children, but the asymptotic complexity remains the same.

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
