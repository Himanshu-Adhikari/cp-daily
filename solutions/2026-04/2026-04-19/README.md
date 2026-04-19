# 📅 Daily CP Solutions — 2026-04-19

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Check If A Number Is Power Of Another
**Platform:** GeeksforGeeks

Problem Insight:
A number y is a power of x if y is 1 (representing x^0) or if y can be repeatedly divided by x until it becomes 1, with each division resulting in a zero remainder.

Approach:
First, handle the edge case where x is 1: y must also be 1. For other cases, repeatedly divide y by x. If y ever has a non-zero remainder when divided by x, or if y does not eventually reduce to 1, then it is not a power of x.

Time Complexity:
O(log_x y)
The loop performs divisions, reducing y by a factor of x in each iteration, leading to a logarithmic number of steps.

Space Complexity:
O(1)
The solution uses a fixed number of variables regardless of input size.

Optimization Notes:
This solution is optimal for checking if y is an integer power of x for positive integers x and y. It correctly handles base cases like x=1 or y=1. Additional checks would be needed for negative inputs or x=0 to prevent undefined behavior like division by zero, but for typical competitive programming constraints (x >= 1, y >= 1), it is efficient and correct.

CODE:
class Solution {
  public:
    bool isPower(int x, int y) {
        if(x==1 and y!=1)return false;
        while(y!=1){
            if(y%x)return false;
            y/=x;
        }
        return true;
    }
};

### 💻 Implementation
```cpp
class Solution {
  public:
    bool isPower(int x, int y) {
        if(x==1 and y!=1)return false;
        while(y!=1){
            if(y%x)return false;
            y/=x;
        }
        return true;
    }
};
```

## 🔹 Leetcode Maximum Distance Between A Pair Of Values
**Platform:** LeetCode

Problem Insight:
The problem requires finding the maximum index difference (j - i) from two non-increasingly sorted arrays, given nums1[i] <= nums2[j] and i <= j.
The sorted property is key to efficiently moving pointers to find potential pairs.

Approach:
Use a two-pointer approach with 'i' for nums1 and 'j' for nums2. If nums1[i] is greater than nums2[j], increment 'i' as nums1[i] is too large for current and subsequent nums2 elements. Otherwise, update the maximum distance with (j - i) and increment 'j' to find a larger distance for the current 'i'.

Time Complexity:
O(N + M)
Both pointers 'i' and 'j' traverse their respective arrays at most once.

Space Complexity:
O(1)
Only a constant number of variables are used for pointers and the result.

Optimization Notes:
It is optimal. The linear time complexity (O(N+M)) is the best possible since, in the worst case, all elements of both arrays may need to be visited.

### 💻 Implementation
```cpp
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0, res = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] > nums2[j]) {
                i++;
            } else {
                res = max(res, j - i);
                j++;
            }
        }
        return res;
    }
};

```
