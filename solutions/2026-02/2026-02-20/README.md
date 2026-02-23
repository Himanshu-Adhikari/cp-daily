# 📅 Daily CP Solutions — 2026-02-20

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Form The Largest Number
**Platform:** GeeksforGeeks

Problem Insight:
This problem involves arranging a list of non-negative integers to form the largest possible number. It's a classic custom sorting problem where standard numerical sorting doesn't apply.

Approach:
The solution defines a custom comparison function that decides the order of two numbers 'a' and 'b' by comparing the string concatenations 'str(a) + str(b)' and 'str(b) + str(a)'. It then uses this custom comparator to sort the array and finally concatenates the sorted numbers (as strings) to form the result, handling the edge case of all zeros.

Time Complexity:
O(N * D log N) where N is the number of elements and D is the maximum number of digits in an integer. Sorting takes O(N log N) comparisons, and each custom comparison takes O(D) due to string operations.

Space Complexity:
O(N * D) where N is the number of elements and D is the maximum number of digits. This space is used for storing string representations of numbers and for intermediate string operations during sorting.

Optimization Notes:
This approach is generally optimal for this problem. The O(N log N) factor from sorting is fundamental for comparison-based sorts, and the O(D) factor per comparison is necessary because digit-by-digit comparison is inherent to the problem's custom ordering.

### 💻 Implementation
```py
class Solution:
    def findLargest(self, arr):
        def compare(a, b):
            if str(a) + str(b) > str(b) + str(a):
                return -1
            elif str(a) + str(b) < str(b) + str(a):
                return 1
            else:
                return 0
        
        arr.sort(key=cmp_to_key(compare))
        res=""
        for i in arr:
            res+=str(i)
        if(res[0]=='0'):return "0"
        return res
        
```

## 🔹 Leetcode 761 Special Binary String
**Platform:** LeetCode

Problem Insight:
A special binary string can be uniquely decomposed into a sequence of smaller special binary strings. To form the lexicographically largest string, these constituent special strings should be sorted in descending order and concatenated.

Approach:
The solution iteratively finds all top-level special substrings (those starting with '1' and ending with '0' with a balanced count). For each found substring, it recursively processes its inner part (excluding the outer '1' and '0') to maximize it. These maximized substrings are then wrapped with '1' and '0' and collected. Finally, all collected special substrings are sorted in reverse lexicographical order and joined.

Time Complexity:
O(N^2)
Justification: String slicing in Python creates new string objects, taking O(length) time. In a worst-case nested structure (e.g., "11...100...0"), each recursive call performs a slice on a string roughly 2 characters shorter, leading to a recurrence T(N) = T(N-2) + O(N), which resolves to O(N^2).

Space Complexity:
O(N^2)
Justification: The recursion depth can be O(N) in the worst case. More significantly, string slicing creates new string objects for each recursive call. The total memory occupied by these new string objects, stored in 'res' lists across all active stack frames, can sum up to O(N^2).

Optimization Notes:
The solution is not optimal due to the O(N^2) time and space complexity primarily caused by string slicing and copying. This can be improved by passing indices (start, end) to the recursive function instead of creating new substring objects. This would reduce the string creation overhead. With this change, the time complexity could be brought down to O(N log N) (due to sorting string chunks) and space complexity to O(N) (for recursion stack and storing result strings).

### 💻 Implementation
```py

class Solution:
    def makeLargestSpecial(self, s: str) -> str:
        count = 0
        i = 0
        res = []
        
        for j in range(len(s)):
            # Track balance: +1 for '1', -1 for '0'
            count += 1 if s[j] == '1' else -1
            
            # Found a balanced chunk when count returns to 0
            if count == 0:
                # Recursively maximize inner part, wrap with 1...0
                res.append('1' + self.makeLargestSpecial(s[i + 1:j]) + '0')
                i = j + 1  # Move to next potential chunk
        
        # Sort chunks in descending order for largest arrangement
        res.sort(reverse=True)
        return ''.join(res)
```
