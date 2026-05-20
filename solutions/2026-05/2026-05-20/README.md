# 📅 Daily CP Solutions — 2026-05-20

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Product Pair
**Platform:** GeeksforGeeks

Problem Insight:
This is a variant of the two-sum problem, adapted for products instead of sums. It requires checking for a pair of numbers (x, y) such that x * y = target.

Approach:
Iterate through the array, using a hash map to store previously seen numbers. For each current number 'c', check if its "complement" (target / c, if c is non-zero and divides target) exists in the map. Handle zero values and target zero carefully.

Time Complexity:
O(N log N)
The loop iterates N times, and map operations (insertion, lookup) take O(log K) time where K is map size (at most N).

Space Complexity:
O(N)
The map stores at most N distinct elements from the input array.

Optimization Notes:
No, it is not optimal. Using std::map results in O(N log N) time complexity. Replacing std::map with std::unordered_map would reduce the average time complexity to O(N), which is generally optimal as each element must be visited once.

### 💻 Implementation
```cpp
class Solution {
  public:
    bool isProduct(vector<int>& arr, long long target) {
        #define ll long long
        map<ll,ll>m;
        for(auto c:arr){
            if(c && target%c==0 && m.count(target/c))return true;
            m[c]=1;
            if(c==0 and target ==0)return true;
        }
        return false;
    }
};
```

## 🔹 Leetcode Find The Prefix Common Array Of Two Arrays
**Platform:** LeetCode

Problem Insight:
The problem requires finding the count of common elements between prefixes of two arrays for each increasing prefix length. Elements are within a known range [1, N].

Approach:
The solution uses two frequency arrays to track elements present in the current prefixes of A and B. For each prefix length, it updates these frequency arrays and then iterates through all possible element values to count how many are present in both arrays' current prefixes.

Time Complexity:
O(N^2)
The outer loop runs N times, and inside it, a nested loop iterates N times to calculate the common count.

Space Complexity:
O(N)
Three vectors (res, ca, cb) of size N are used to store the results and frequency counts.

Optimization Notes:
The solution is not optimal. The common count can be updated in O(1) time at each step instead of O(N). By maintaining a running count and checking if newly added elements become common, the total time complexity can be reduced to O(N).

### 💻 Implementation
```cpp
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int>res(n),ca(n),cb(n);
            int c=0;
        for(int i=0;i<n;i++){
            c=0;
            ca[A[i]-1]++,cb[B[i]-1]++;
            for(int j=0;j<n;j++)c+=(ca[j] && cb[j]);
            res[i]=c;
        }
        return res;
    }
};
```
