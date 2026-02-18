# 📅 Daily CP Solutions — 2026-02-18

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Count Inversions
**Platform:** GeeksforGeeks

Problem Insight:
The problem is to count pairs (i, j) such that i < j and arr[i] > arr[j]. This is a classic application of the merge sort algorithm.

Approach:
The solution uses a modified merge sort. Inversions are counted during the merge step: if an element from the right subarray is smaller than an element from the left subarray, it forms inversions with all remaining elements in the left subarray. The total count is the sum of inversions from recursive calls and the merge step.

Time Complexity:
O(N log N)
The merge sort algorithm has a time complexity of O(N log N) for sorting, and counting inversions adds a constant amount of work to each merge step.

Space Complexity:
O(N)
An auxiliary array of size N is used in the merge function to store the sorted elements during the merge process.

Optimization Notes:
This solution is optimal for comparison-based algorithms. Counting inversions requires at least O(N log N) time, which merge sort achieves.

### 💻 Implementation
```cpp
class Solution {
  public:
     int Merge(vector<int> &arr, int l, int m, int r)
    {
        vector<int> merged(r-l+1);
        int i = l, j = m+1, k = 0, cnt = 0;
        while(i<m+1 and j<r+1){
            if(arr[i]>arr[j]){
                merged[k] = arr[j];
                cnt+=(m-i+1);
                j++;
            }
            else{
                merged[k] = arr[i];
                i++;
            }
            k++;
        }
        while(i<m+1){
            merged[k] = arr[i];
            i++;
            k++;
        }
        while(j<r+1){
            merged[k] = arr[j];
            j++;
            k++;
        }
        
        for(int i = 0;i<(r-l+1);i++)
        {
            arr[l+i] = merged[i];
        }
        return cnt;
    }
    int MergeSort(vector<int> &arr, int l, int r){
        if(l>=r)return 0;
        int m = l + (r-l)/2;
        int lc = MergeSort(arr, l, m);
        int rc = MergeSort(arr, m+1, r);
        
        int mc = Merge(arr, l, m, r);
        
        return lc+rc+mc;
    }
    int inversionCount(vector<int> &arr) {
        return MergeSort(arr, 0, arr.size()-1);
    }
};
```

## 🔹 Leetcode Binary-Number-With-Alternating-Bits
**Platform:** LeetCode

Problem Insight:
The problem asks to determine if the binary representation of a given integer has bits that strictly alternate (e.g., 10101 or 01010).

Approach:
The solution converts the integer into its binary string representation. It then iterates through this string, checking if any adjacent bits are identical. If any identical adjacent bits are found, it immediately returns False; otherwise, it returns True after checking all pairs.

Time Complexity:
O(log n) because converting the integer to a binary string and iterating through it takes time proportional to the number of bits in n, which is log_2(n).

Space Complexity:
O(log n) because storing the binary string representation requires space proportional to the number of bits in n, which is log_2(n).

Optimization Notes:
The solution is not optimal. While its time complexity is reasonable, using string conversion and comparison is less efficient than a purely bitwise approach. An optimal solution can be achieved using bit manipulation, such as checking if (n XOR (n >> 1)) is a number consisting of all 1s. This avoids string allocations and potentially improves constant factors.

### 💻 Implementation
```py
class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        a=bin(n)[2::]
        if(sum(1 if a[i]==a[i-1] else 0 for i in range(1,len(a)))):
            return False
        return True
```
