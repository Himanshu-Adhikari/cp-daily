# 📅 Daily CP Solutions — 2026-02-02

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Maximum Sum In Circular Array
**Platform:** GeeksforGeeks

Problem Insight:
The maximum circular subarray sum is either a non-wrapping subarray sum or a wrapping subarray sum. A wrapping subarray sum is equivalent to the total array sum minus the minimum non-wrapping subarray sum.

Approach:
Calculate the maximum subarray sum using Kadane's algorithm and simultaneously calculate the minimum subarray sum (also using a variation of Kadane's) and the total sum of the array. The final answer is the maximum of the maximum subarray sum found, and (total sum - minimum subarray sum), with special handling for the case where all elements are negative.

Time Complexity:
O(N)
The solution iterates through the array once to compute the maximum non-wrapping sum, minimum non-wrapping sum, and total sum.

Space Complexity:
O(1)
The solution uses a fixed number of variables independent of the input array size.

Optimization Notes:
The solution is optimal. It processes each array element a constant number of times, resulting in linear time complexity, which is the theoretical minimum for this problem. It also uses constant extra space.

### 💻 Implementation
```cpp
class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
         int n = arr.size();
           int mini = INT_MAX, minsum = 0;
           int maxi = INT_MIN, maxsum = 0;
           int total =0;
           for(int i:arr){
                    total+=i;
                    minsum+=i;
                    maxsum+=i;
                    mini = min(mini, minsum);
                    maxi = max(maxi, maxsum);
                    if(minsum>0){
                         minsum=0;
                    }
                    if(maxsum<0){
                          maxsum=0;
                    }
                    
           }
          if(maxi<0) return maxi;
           
           return max(maxi, total-mini);
    }
};
```

## 🔹 Leetcode Divide-An-Array-Into-Subarrays-With-Minimum-Cost-Ii
**Platform:** LeetCode

Problem Insight:
The goal is to find the minimum sum of k elements, always including nums[0]. The remaining k-1 elements consist of nums[i] (the rightmost among these k-1) and k-2 smallest elements chosen from a sliding window defined by i and dist.

Approach:
The solution fixes nums[0] and iterates through all possible indices i (from k-1 to n-1) for the second chosen element. For each i, a two-multiset structure (Container class) efficiently maintains the sum of the k-2 smallest elements within the candidate window nums[max(1, i-dist)...i-1]. The minimum sum of nums[0] + nums[i] + Container.sum() across all valid i is the answer.

Time Complexity:
O(N log K)
Container operations (add, erase, adjust, sum) take O(log K) time due to multiset usage. The Container is initialized with O(K) elements and then updated O(N) times, resulting in O(N log K) total time.

Space Complexity:
O(dist)
The Container class stores elements from a sliding window whose maximum size is dist. Therefore, the multisets will collectively hold at most dist elements, yielding O(dist) space complexity.

Optimization Notes:
The solution is optimal for this problem. The use of two multisets is a standard and efficient technique for maintaining the sum of k-smallest elements in a sliding window, providing logarithmic time complexity for updates and queries.

### 💻 Implementation
```cpp
// two multisets maintain the first k smallest values
class Container {
public:
    Container(int k) : k(k), sm(0) {}

    // adjust the size of the ordered set to ensure that the first k smallest
    // values are all in st1
    void adjust() {
        while (st1.size() < k && st2.size() > 0) {
            int x = *(st2.begin());
            st1.emplace(x);
            sm += x;
            st2.erase(st2.begin());
        }
        while (st1.size() > k) {
            int x = *prev(st1.end());
            st2.emplace(x);
            st1.erase(prev(st1.end()));
            sm -= x;
        }
    }

    // insert element x
    void add(int x) {
        if (!st2.empty() && x >= *(st2.begin())) {
            st2.emplace(x);
        } else {
            st1.emplace(x);
            sm += x;
        }
        adjust();
    }

    // delete element x
    void erase(int x) {
        auto it = st1.find(x);
        if (it != st1.end()) {
            st1.erase(it), sm -= x;
        } else {
            st2.erase(st2.find(x));
        }
        adjust();
    }

    // sum of the first k smallest elements
    long long sum() { return sm; }

private:
    int k;
    // st1 saves the k smallest values, st2 saves the other values
    multiset<int> st1, st2;
    // sm represents the sum of the first k smallest elements
    long long sm;
};

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        // sliding window initialization
        Container cnt(k - 2);
        for (int i = 1; i < k - 1; i++) {
            cnt.add(nums[i]);
        }

        long long ans = cnt.sum() + nums[k - 1];
        // enumerate the beginning of the last array
        for (int i = k; i < n; i++) {
            int j = i - dist - 1;
            if (j > 0) {
                cnt.erase(nums[j]);
            }
            cnt.add(nums[i - 1]);
            ans = min(ans, cnt.sum() + nums[i]);
        }

        return ans + nums[0];
    }
};
```
