# 📅 Daily CP Solutions — 2026-02-16

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Meeting Rooms
**Platform:** GeeksforGeeks

Problem Insight:
This problem determines if a set of time intervals (meetings) can all be attended without any overlaps. The core challenge is to efficiently detect any single instance where one meeting begins before a previous one ends.

Approach:
The solution first sorts all meetings by their start times. It then iterates through the sorted meetings, comparing each meeting's start time with the end time of the immediately preceding meeting. If a meeting starts before the prior one ends, an overlap is detected, and it returns False. If no overlaps are found after checking all consecutive pairs, it returns True.

Time Complexity:
O(N log N)
The dominant operation is sorting the N meetings, which takes O(N log N) time. The subsequent linear scan takes O(N) time.

Space Complexity:
O(N)
Python's default sort (Timsort) can use up to O(N) auxiliary space in the worst case for temporary storage during the sorting process.

Optimization Notes:
This solution is optimal. Sorting is generally required to order the intervals, which takes O(N log N) time. Any approach that doesn't sort would likely involve checking all pairs of intervals, resulting in a less efficient O(N^2) time complexity.

CODE:
class Solution:
    def canAttend(self, arr):
        arr.sort()
        n=len(arr)
        for i in range(1,n):
            if(arr[i][0]<arr[i-1][1]):return False
        return True

### 💻 Implementation
```py
class Solution:
    def canAttend(self, arr):
        arr.sort()
        n=len(arr)
        for i in range(1,n):
            if(arr[i][0]<arr[i-1][1]):return False
        return True
```

## 🔹 Leetcode 190 Reverse Bits
**Platform:** LeetCode

Problem Insight:
The task is to reverse the order of all 32 bits in an unsigned integer. This means the most significant bit becomes the least significant and vice versa.

Approach:
The solution converts the input integer into a 32-bit bitset. It then reverses the order of bits in this bitset using a two-pointer swap strategy. Finally, it reconstructs the integer value from the reversed bitset by summing up powers of two.

Time Complexity:
O(1)
Operations on a fixed 32-bit integer (bitset creation, reversal, reconstruction) all take constant time.

Space Complexity:
O(1)
A bitset of fixed size 32 bits and a few integer variables consume constant memory.

Optimization Notes:
The solution is optimal as it performs a fixed number of operations directly proportional to the bit width (32). Direct bit manipulation using shifts and ORs without a bitset could be marginally faster due to less overhead, but both approaches are O(1).

### 💻 Implementation
```cpp
class Solution {
public:
    int reverseBits(int n) {
        #define ll long long
        bitset<32>a(n);
        int i=0,j=31;
        while(i<=j){
            int t=a[i];
            a[i++]=a[j];
            a[j--]=t;
        }
        ll res=0;
        for(int i=0;i<32;i++){
            if(a[i])res+=(1ll<<i);
        }
        return res;
    }
};
```
