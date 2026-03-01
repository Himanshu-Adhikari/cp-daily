# 📅 Daily CP Solutions — 2026-03-01

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Move Zeroes To The End
**Platform:** GeeksforGeeks

Problem Insight:
Rearrange an array by moving all non-zero elements to its beginning while preserving their relative order, then fill the remaining positions with zeros.

Approach:
First, iterate through the array to copy non-zero elements to the start using a 'write' pointer and count all zeros.
Second, fill the remaining positions from the 'write' pointer to the end of the array with zeros, based on the counted number of zeros.

Time Complexity:
O(N) because the solution iterates through the array twice, each pass taking linear time proportional to the array size N.

Space Complexity:
O(1) because it modifies the array in-place and uses only a constant number of auxiliary variables for pointers and counts.

Optimization Notes:
This solution is optimal in both time and space complexity. An O(N) time is required to check all elements, and O(1) space is achieved by performing modifications directly within the input array. No further asymptotic improvements are possible.

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
Each digit 'd' in the input string 'n' requires 'd' numbers to have a '1' at that position.
The maximum digit present in 'n' determines the minimum count of required partitions.

Approach:
Iterate through the string 'n' to find the character representing the largest digit.
Convert this largest digit character to an integer to get the minimum number of partitions.

Time Complexity:
O(L), where L is the length of string n.
The solution iterates through the input string once to find the maximum digit.

Space Complexity:
O(1)
Only a few constant space variables are used to track the maximum digit.

Optimization Notes:
This solution is optimal. It inherently requires at least one pass through the input string to identify the maximum digit, which this approach achieves.

### 💻 Implementation
```py
class Solution:
    def minPartitions(self, n: str) -> int:
        return int(max(n))
```
