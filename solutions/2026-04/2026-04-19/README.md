# 📅 Daily CP Solutions — 2026-04-19

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Check If A Number Is Power Of Another
**Platform:** GeeksforGeeks

Problem Insight:
The problem checks if a given integer y can be expressed as an integer power of another integer x (i.e., y = x^k for some integer k >= 0).

Approach:
The solution iteratively divides y by x until y becomes 1. If at any point y is not divisible by x, or if x is 1 and y is not 1, then y is not a power of x.

Time Complexity:
O(log_x y)
The loop divides y by x in each iteration, so the number of iterations is logarithmic with base x.

Space Complexity:
O(1)
The solution uses a constant amount of extra space for variables.

Optimization Notes:
This solution is optimal for checking if y is a power of x for positive integers x and y. The inherent nature of the problem requires divisions proportional to the logarithm of y.

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
The problem seeks the maximum distance j-i for valid pairs (i, j) where nums1[i] <= nums2[j] and both arrays are non-increasing. The non-increasing property is crucial for the two-pointer strategy.

Approach:
A two-pointer approach is used. Pointer 'i' moves through nums1, 'j' through nums2. If nums1[i] is greater than nums2[j], 'i' must increment. Otherwise, a valid distance j-i is calculated and 'j' increments to find a potentially larger distance.

Time Complexity:
O(N + M)
Both pointers 'i' and 'j' traverse their respective arrays at most once.

Space Complexity:
O(1)
Only a few constant integer variables are used for pointers and the result.

Optimization Notes:
It is optimal. The algorithm processes each element from both arrays at most once, achieving a linear time complexity which is the best possible as all elements may need to be inspected.

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
