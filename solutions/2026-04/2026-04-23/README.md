# 📅 Daily CP Solutions — 2026-04-23

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Split An Array Intro Two Equal Sum Subarray
**Platform:** GeeksforGeeks

Problem Insight:
The problem determines if an array can be partitioned into two contiguous subarrays with equal sums. This requires finding a prefix sum that equals exactly half of the array's total sum.

Approach:
First, compute the total sum of all elements in the array. Then, iterate through the array, maintaining a running sum of elements encountered so far (the prefix sum). In each step, compare this prefix sum with the remaining sum of elements (total sum minus prefix sum). If they are equal, a valid split exists.

Time Complexity:
O(N), where N is the number of elements in the array. The solution iterates through the array once to calculate the total sum and once more to find a split point.

Space Complexity:
O(1). The solution uses a few constant variables to store sums and pointers, independent of the input array size.

Optimization Notes:
The solution is optimal. It achieves O(N) time complexity, which is the minimum required as every element must be processed at least once to determine the sums. It also uses O(1) additional space, which is optimal for space complexity.

### 💻 Implementation
```py
class Solution:
    def canSplit(self, arr):
        sm=sum(arr)
        cur=0
        for i in arr:
            cur+=i
            sm-=i
            if(cur==sm):return True
        return False
```

## 🔹 Leetcode Sum Of Distances
**Platform:** LeetCode

Problem Insight:
The problem asks to calculate, for each index i, the sum of absolute differences between i and all other indices j where nums[i] equals nums[j]. This means we should group indices by their corresponding number.

Approach:
First, group all indices for each unique number. Then, for each group of sorted indices, precompute their prefix and suffix sums. Finally, iterate through the original array; for each element at index i, find its position in its group and use the precomputed prefix/suffix sums to efficiently calculate the total distance to other elements in that group.

Time Complexity:
O(N log N).
Justification: Populating the map with N elements takes O(N log K) (where K is number of distinct elements). Precomputing prefix/suffix sums for all groups takes O(N) total. The final loop iterates N times, each requiring O(log S) for lower_bound (where S is group size, max N) and O(log K) for map access.

Space Complexity:
O(N).
Justification: The map stores all N indices across its value vectors, and the prefix/suffix sum maps also store N elements in total. The result vector stores N elements.

Optimization Notes:
The solution is optimal. It uses a common technique for range sum queries (prefix/suffix sums) after grouping elements. The O(N log N) complexity arises from using a map to group elements and lower_bound to find positions, which is generally efficient for this type of problem. Achieving better than O(N log N) is unlikely given the need to process all N elements and potentially search within sorted groups.

### 💻 Implementation
```cpp
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        #define ll long long
        vector<ll>res;
        map<int,vector<ll>>m,mp,sp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]].push_back(i);
        }
        for(auto [a,b]:m){
            ll sm=0;
            for(auto c:b){
                sm+=c;
                mp[a].push_back(sm);
            }
            int s=b.size();
            sm=0;
            for(int i=s-1;i>=0;i--){
                sm+=b[i];
                sp[a].push_back(sm);
            }
            reverse(begin(sp[a]),end(sp[a]));
        }
        for(int i=0;i<n;i++){
            int s=m[nums[i]].size();
            if(s==1)res.push_back(0);
            else{
                int id=lower_bound(m[nums[i]].begin(),end(m[nums[i]]),i)-begin(m[nums[i]]);
               long long left = (long long)id * i - (id ? mp[nums[i]][id - 1] : 0);
                long long right = (sp[nums[i]][id] - i) - (long long)(s - id - 1) * i;
                res.push_back(left + right);
            }
        }
        return res;
    }
};
```
