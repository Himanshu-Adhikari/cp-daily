# 📅 Daily CP Solutions — 2026-02-10

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Koko Eating Bananas
**Platform:** GeeksforGeeks

Problem Insight:
Find the minimum integer eating speed that allows finishing all banana piles within given hours. The time taken is monotonically decreasing with increasing speed, enabling binary search.

Approach:
Employ binary search on the possible range of eating speeds. For each candidate speed, calculate the total hours needed to eat all piles. Adjust the search range based on whether the total hours exceed the allowed limit.

Time Complexity:
O(N * log(MaxPileSize)). The binary search performs log(MaxPileSize) iterations, and each iteration involves an O(N) loop to sum the hours for all piles.

Space Complexity:
O(1). The solution uses a constant amount of extra space for variables during the calculation.

Optimization Notes:
The solution is optimal for this problem's constraints and type. The upper bound for binary search could be set more precisely to max(arr) instead of a large constant like 10**15, though it doesn't change asymptotic complexity.

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
The problem seeks the longest subarray where the number of unique odd elements equals the number of unique even elements. The provided solution employs a brute-force check of all possible subarrays.

Approach:
Iterate through all possible starting indices 'i' and ending indices 'j' of subarrays. For each subarray [i, j], count the unique odd and unique even numbers present. If these counts are equal, update the maximum length found so far.

Time Complexity:
O(N^2 log N)
The outer loop runs N times, the inner loop runs up to N times, and map operations (count, insert) take O(log N) in the worst case.

Space Complexity:
O(N)
A map is used to track unique elements within each subarray, storing up to N distinct elements in the worst case.

Optimization Notes:
The solution is not optimal. It re-calculates unique odd and even counts for every possible subarray from scratch. A more efficient approach could involve a sliding window or using a hash map to store prefix balance values, potentially achieving O(N) or O(N log N) time complexity by incrementally updating counts and using a frequency map to track uniqueness as the window slides.

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
