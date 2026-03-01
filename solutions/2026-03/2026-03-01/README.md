# 📅 Daily CP Solutions — 2026-03-01

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Move Zeroes To The End
**Platform:** GeeksforGeeks

Problem Insight:
The problem requires reordering an array to place all zero elements at the end while preserving the relative order of non-zero elements.

Approach:
The solution uses two passes. The first pass moves all non-zero elements to the beginning of the array and counts the total number of zeros. The second pass then fills the remaining positions at the end of the array with the counted zeros.

Time Complexity:
O(N)
The first loop iterates N times and the second loop iterates at most N times, resulting in linear time complexity.

Space Complexity:
O(1)
Only a few constant extra variables (ct, n, ptr) are used, independent of the input array size.

Optimization Notes:
It is optimal. The solution achieves O(N) time complexity because each element is processed a constant number of times, and O(1) space complexity as it modifies the array in-place without auxiliary data structures.

### 💻 Implementation
```cpp
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
         int ct = 0;
        int n = arr.size();
        int ptr = 0;
        for(int i=0;i<n;i++){
            if(arr[i] > 0){
                arr[ptr] = arr[i];
                ptr++;
            }
            else{
                ct++;
            }
        }
        for(int i=n-1;ct>0;ct--){
            arr[i--] = 0; 
        }
    }
};

```

## 🔹 Leetcode 1689 Partitioning-Into-Minimum-Number-Of-Deci-Binary-Numbers
**Platform:** LeetCode

Problem Insight:
The minimum number of deci-binary numbers required to sum up to a given number is determined by its largest digit. Each deci-binary number can contribute at most 1 to any specific digit place.

Approach:
Identify the largest digit present in the input string representation of the number. This largest digit directly corresponds to the minimum count of deci-binary numbers needed.

Time Complexity:
O(L) where L is the length of the string n. We iterate through the string once to find the maximum character.

Space Complexity:
O(1). We only store a few variables (the maximum character found so far) irrespective of the input string's length.

Optimization Notes:
This solution is optimal. It directly computes the minimum possible value, and the computation involves a single pass through the input string, which is the most efficient way to access all digits.

### 💻 Implementation
```py
class Solution:
    def minPartitions(self, n: str) -> int:
        return int(max(n))
```
