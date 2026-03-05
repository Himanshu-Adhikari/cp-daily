# 📅 Daily CP Solutions — 2026-03-05

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Longest-K-Unique-Characters-Substring
**Platform:** GeeksforGeeks

Problem Insight:
The problem asks for the length of the longest substring within a given string that contains exactly K distinct characters. It should return -1 if no such substring exists.

Approach:
The solution uses a sliding window technique with two pointers, 'i' (end of window) and 'j' (start of window), and a frequency map (dictionary 'd') to keep track of character counts within the current window. It expands the window by incrementing 'i', adds characters to 'd', and shrinks the window by incrementing 'j' and removing characters from 'd' if the number of distinct characters in the window exceeds 'k'. When the window has exactly 'k' distinct characters, it updates the maximum length found so far. An initial check returns -1 if the total distinct characters in the entire string are less than 'k'.

Time Complexity:
O(N)
Both pointers 'i' and 'j' traverse the string at most once. Dictionary operations (get, put, delete, len) take O(1) on average.

Space Complexity:
O(N)
In the worst case, the dictionary 'd' could store up to N distinct characters (if k=N), and the set 'a' also stores up to N distinct characters. If the character set is limited (e.g., ASCII), it would be O(1) or O(Alphabet_Size).

Optimization Notes:
The solution is optimal in terms of time complexity, achieving linear time (O(N)) which is the best possible as every character must be examined at least once. The initial check for `len(a) < k` is a good early exit to handle cases where it's impossible to find 'k' distinct characters. The current return logic (returning 'res') is correct as 'res' will be > 0 if a valid substring is found, and the initial check handles the -1 case.

### 💻 Implementation
```py
class Solution:
    def longestKSubstr(self, s, k):
       a=set(s)
       if(len(a)<k):return -1
       d={}
       n=len(s)
       j=0
       res=0
       for i in range(n):
          d[s[i]]=d.get(s[i],0)+1
          while(len(d)>k):
              d[s[j]]-=1
              if(d[s[j]]==0):
                  del d[s[j]]
              j+=1
          if(len(d)==k):
              res=max(res,i-j+1)
       return res
```

## 🔹 Leetcode Minimum-Changes-To-Make-Alternating-Binary-String
**Platform:** LeetCode

Problem Insight:
The problem requires finding the minimum operations to transform a binary string into an alternating one. There are only two possible alternating target patterns: one starting with '0' (e.g., "0101...") and one starting with '1' (e.g., "1010...").

Approach:
The solution uses a single pass through the input string, maintaining two counts. One count tracks the operations needed to match the "0101..." pattern, and the other tracks operations for the "1010..." pattern. For each character, it compares it against the expected character for both patterns and increments the respective operation count if there is a mismatch. The minimum of these two final counts is the answer.

Time Complexity:
O(N)
The solution iterates through the input string of length N exactly once.

Space Complexity:
O(1)
It uses a fixed number of variables regardless of the input string's length.

Optimization Notes:
It is optimal. The solution processes each character of the string once, which is the minimum necessary to inspect the entire input. No extra data structures are used.

### 💻 Implementation
```py
class Solution:
    def minOperations(self, s: str) -> int:
        a,b=0,0
        f,p="0","1"
        for i in s:
            if(p!=i):b+=1
            if(f!=i):a+=1
            p='1' if p=='0' else '0'
            f='1' if f=='0' else '0'
        return min(a,b)
        
```
