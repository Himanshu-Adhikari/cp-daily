# 📅 Daily CP Solutions — 2026-03-03

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Fruit-Into-Baskets
**Platform:** GeeksforGeeks

Problem Insight:
The problem aims to find the longest subarray that contains at most two distinct elements. This is a classic sliding window problem variant.

Approach:
The solution uses a sliding window approach with two pointers, i and j, and a frequency map. The window expands by incrementing 'i', adding elements to the map. If the number of distinct elements in the window (map size) exceeds two, the window shrinks from the left by incrementing 'j' and removing elements from the map until the distinct count is back to at most two. The maximum window length is tracked.

Time Complexity:
O(N)
Each element is processed by pointer 'i' once and by pointer 'j' once. Map operations take O(log K) time where K is the number of distinct elements in the map, but K is kept small (at most 3) by the window shrinking logic, making map operations effectively O(1).

Space Complexity:
O(1)
The map 'm' stores at most 3 distinct elements and their counts at any given time, thus its space usage is constant.

Optimization Notes:
The solution is optimal in terms of both time and space complexity, achieving O(N) time and O(1) space. A single pass is generally the best one can do for this type of problem. While using an unordered_map might offer average O(1) map operations versus a map's O(log K), for the constrained K in this problem, the practical performance difference is negligible, and both achieve the same optimal overall complexity.

### 💻 Implementation
```cpp
class Solution {
  public:
    int totalElements(vector<int> &arr) {
        map<int,int>m;
        int n=arr.size();
        int res=1;
        for(int i=0,j=0;i<n;i++){
            m[arr[i]]++;
            while(int(m.size())>2){
                m[arr[j]]--;
                if(m[arr[j]]==0)m.erase(arr[j]);
                j++;
            }
            res=max(res,i-j+1);
        }
        return res;
    }
};
```

## 🔹 Leetcode Find-Kth-Bit-In-Nth-Binary-String
**Platform:** LeetCode

Problem Insight:
This problem defines a recursive sequence of binary strings S_n and asks for the k-th character. The sequence doubles in length in each step, making explicit construction for large n or k inefficient.

Approach:
The solution iteratively builds the binary string S_n based on the given recursive rule. It continues this construction until the string's length is at least k, then returns the character at the specified index.

Time Complexity:
O(k)
Each iteration of the loop involves string operations proportional to the current string's length, which grows exponentially. The total work sums up to O(k) as the final string built can be up to roughly 2k characters long.

Space Complexity:
O(k)
The algorithm explicitly stores the full string S_n in memory, which can have a length up to approximately 2k-1, along with temporary copies during string manipulation.

Optimization Notes:
The solution is not optimal as it explicitly constructs the entire string. An optimal approach would use recursion or iteration to determine the k-th bit directly in O(n) time (where n is the recursion depth, approximately log k) and O(n) space by analyzing the bit's position within the S_n structure.

### 💻 Implementation
```py
class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        s="0"
        while(len(s)<k):
            t=s
            s+='1'
            p=""
            for i in t:
                if i=='1':p+='0'
                else:p+='1'
            s+=p[::-1]
        return s[k-1]
```
