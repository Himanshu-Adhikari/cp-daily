# 📅 Daily CP Solutions — 2026-02-10

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Koko Eating Bananas
**Platform:** GeeksforGeeks

Problem Insight:
This problem requires finding the minimum possible eating speed (kilos per hour) for Koko to finish all banana piles within a given total time limit. It is solved using binary search on the answer.

Approach:
The solution employs binary search over the range of possible eating speeds. For each candidate speed, it calculates the total hours needed to consume all banana piles. If the total hours are within the limit, it tries smaller speeds; otherwise, it tries larger speeds.

Time Complexity:
O(N * log(MAX_PILE_SIZE))
Binary search performs log(MAX_PILE_SIZE) iterations, and each iteration involves a linear scan through N piles.

Space Complexity:
O(1)
The solution uses only a constant amount of extra space for variables.

Optimization Notes:
The solution is optimal. The upper bound for the binary search can be max(arr) instead of 10^15 for a tighter search range, but this does not change the asymptotic complexity. The 'if m > i' check is equivalent to the general ceiling division and could be omitted for slightly cleaner code without affecting correctness or complexity.

### 💻 Implementation
```py
class Solution:
    def kokoEat(self, arr, k):
        l=1
        h=10**15
        n=len(arr)
        while(l<=h):
            c=0
            m=l+(h-l)//2
            for i in arr:
                if(m>i):c+=1
                else:c+=((i+m-1)//m)
            if(c<=k):h=m-1
            else:l=m+1
        return l
        
```

## 🔹 Leetcode Longest-Balanced-Subarray-I
**Platform:** LeetCode

Problem Insight:
The problem seeks the longest continuous subarray where the count of distinct odd numbers is exactly equal to the count of distinct even numbers within that subarray.

Approach:
The solution uses a brute-force approach by iterating through all possible subarrays. For each subarray, it maintains a count of unique odd and unique even numbers using a hash map to track seen elements. If the unique odd and even counts are equal, the subarray length is checked against the maximum result.

Time Complexity:
O(N^2 log N). The nested loops run O(N^2) times, and map operations inside the inner loop take O(log N) time in the worst case.

Space Complexity:
O(N). The hash map stores unique elements for the current subarray, potentially up to N distinct elements.

Optimization Notes:
The solution is not optimal. Its O(N^2 log N) time complexity is inefficient for larger inputs (N > 5000). An optimal solution would likely achieve O(N) or O(N log N) by employing a more sophisticated approach, such as a sliding window with frequency maps to efficiently track unique counts or a hash map for storing (unique_odd_count - unique_even_count) states encountered.

### 💻 Implementation
```cpp
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        for(int i=0;i<n;i++){
            int o=0,e=0;
            map<int,int>m;
            for(int j=i;j<n;j++){
                if(!m.count(nums[j])){
                if(nums[j]%2 )o++;
                else e++;
                }
                m[nums[j]]=1;
                if(o==e)res=max(res,j-i+1);
            }
        }
        return res;
    }
};
```
