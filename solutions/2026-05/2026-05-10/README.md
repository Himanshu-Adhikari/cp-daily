# 📅 Daily CP Solutions — 2026-05-10

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Max Progit Of Two Machines
**Platform:** GeeksforGeeks

Problem Insight:
The problem requires selecting one element from each of N pairs (a[i], b[i]) to maximize total profit. There are constraints on the total number of 'a' selections (x) and 'b' selections (y), with x + y = N.

Approach:
The solution employs a greedy strategy. It sorts the items based on the absolute difference between a[i] and b[i] in descending order. For each item in this sorted order, it picks the larger value (a[i] or b[i]) if its corresponding budget (x or y) is available. If the preferred budget is exhausted, it selects the other item.

Time Complexity:
O(N log N)
The dominant operation is sorting the auxiliary index vector of N elements.

Space Complexity:
O(N)
An auxiliary vector of N integers is used to store indices for sorting.

Optimization Notes:
The solution is optimal. The greedy approach correctly identifies that prioritizing choices with the largest difference between a[i] and b[i] minimizes the potential "loss" when forced to pick the less preferred option due to budget constraints. No further improvements to time or space complexity are possible given the need to sort.

### 💻 Implementation
```cpp
class Solution {
  public:
    int maxProfit(int x, int y, vector<int> &a, vector<int> &b) {
        int res=0;
        int n=a.size();
        vector<int>aux(n);
        iota(begin(aux),end(aux),0);
        sort(begin(aux),end(aux),[&](int i,int j){
            return abs(a[i]-b[i])>abs(b[j]-a[j]);
        });
        for(int j=0;j<n;j++){
            int i=aux[j];
            if(a[i]>b[i]){
                if(x){res+=a[i];x--;}
                else{res+=b[i];y--;}
            }
            else{
                if(y){res+=b[i];y--;}
                else{res+=a[i];x--;}
            }
        }
        return res;
    }
};
```

## 🔹 Leetcode Min Jumps To Reach The Last Index
**Platform:** LeetCode

Problem Insight:
This problem asks for the maximum number of jumps to reach the last index from the first, constrained by the absolute difference between values. It's a longest path problem on a directed acyclic graph.

Approach:
The solution uses dynamic programming to find the maximum jumps. It iterates through all pairs (i, j) where i < j, checking if a jump from i to j is valid, and updates the maximum jumps to reach j.

Time Complexity:
O(N^2)
Two nested loops iterate over all possible pairs (i, j) with i < j, performing constant time operations.

Space Complexity:
O(N)
A vector of size N is used to store the maximum jumps to each index.

Optimization Notes:
This solution is optimal for the given problem constraints and definition. Since every potential jump between distinct indices i and j (where i < j) must be considered, which amounts to O(N^2) pairs, an O(N^2) complexity is expected.

### 💻 Implementation
```cpp
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>a(n,0);
        a[0]=1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(abs(nums[i]-nums[j])<=target and a[i]){
                    a[j]=max(a[j],a[i]+1);
                }
            }
        }
        return a[n-1]?a[n-1]-1:-1;
    }
};
```
