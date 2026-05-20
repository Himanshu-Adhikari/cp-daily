# 📅 Daily CP Solutions — 2026-05-20

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Product Pair
**Platform:** GeeksforGeeks

Problem Insight:
The problem asks to find if any two numbers in an array multiply to a given target. It correctly handles scenarios involving zero and duplicate elements.

Approach:
The solution iterates through the input array, using a hash map to store numbers encountered so far. For each number, it checks if the required "complement" (target / current number) is already in the map, indicating a product pair. Special conditions for zero values are handled.

Time Complexity:
O(N log N)
Each element is processed once, and map operations (insertion, lookup) take O(log N) time in the worst case for a balanced tree map.

Space Complexity:
O(N)
The map stores up to N distinct elements from the input array.

Optimization Notes:
The solution is not optimal for average-case performance. Using std::unordered_map instead of std::map would improve the average time complexity to O(N) due to average O(1) lookups and insertions for hash-based maps.

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
The problem asks to find, for each prefix length i, the count of numbers that are present in both the prefix A[0...i] and B[0...i].

Approach:
The solution iterates through each prefix length i. For each prefix, it updates two boolean presence arrays (ca and cb) to mark numbers seen in A[0...i] and B[0...i] respectively. Then, it iterates through all possible numbers (1 to N) to count how many are marked in both ca and cb.

Time Complexity:
O(N^2)
The outer loop runs N times, and the inner loop to calculate the common count also runs N times in each iteration.

Space Complexity:
O(N)
The result vector (res) and two boolean presence arrays (ca, cb) each take O(N) space.

Optimization Notes:
The current solution is not optimal. It can be optimized to O(N). The inner loop that recomputes the entire common count for each prefix is redundant. An optimized approach would maintain the common count incrementally by only checking if A[i] or B[i] becoming present in their respective prefix leads to a new common element. This would involve constant time updates to the common count in each step of the main loop.

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
