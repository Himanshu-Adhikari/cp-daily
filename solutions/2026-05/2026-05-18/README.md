# 📅 Daily CP Solutions — 2026-05-18

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Maximum Sum Problem
**Platform:** GeeksforGeeks

Problem Insight:
This problem aims to find the maximum sum obtainable from an integer n by either choosing a modified value of n or replacing it with the sum of the maximum sums of its divided parts (n/2, n/3, n/4). It is a recursive optimization problem with overlapping subproblems.

Approach:
The solution employs direct recursion with a defined base case. For n less than 12, it returns n. For n 12 or greater, it computes the maximum between a derived value (13*(n/12)) and the sum of recursive calls to maxSum for n/2, n/3, and n/4.

Time Complexity:
Exponential.
Justification: The solution recomputes identical subproblems multiple times, leading to an exponential growth in the number of recursive calls as n increases.

Space Complexity:
O(log n)
Justification: The space used is determined by the maximum depth of the recursion stack, which is logarithmic as n is repeatedly divided by at least 2.

Optimization Notes:
The solution is not optimal. Its exponential time complexity can be drastically improved by implementing memoization (dynamic programming). Storing the results of maxSum(k) in a hash map or array and reusing them would reduce the time complexity to O(n).

### 💻 Implementation
```cpp
class Solution {
  public:
    int maxSum(int n) {
        if(n<12)return n;
        return max(13*(n/12),maxSum(n/2) + maxSum(n/3) + maxSum(n/4));
    }
};
```

## 🔹 Leetcode Jump Game Iv
**Platform:** LeetCode

Problem Insight:
This is a shortest path problem on an unweighted graph, requiring a Breadth-First Search (BFS) to find the minimum number of jumps. The "same value" jump rule creates a dense connectivity that needs careful handling.

Approach:
The solution uses BFS. It initializes a map to store all indices for each value, allowing efficient lookup of same-value jump targets. During BFS, it explores adjacent indices and all indices with the same value. A visited array prevents cycles and redundant work. The map entries for a value are effectively cleared after that value's group of indices has been processed, optimizing same-value jumps to avoid reprocessing.

Time Complexity:
O(N log N)
Each node is visited once. Direct jumps are O(1). Same-value jumps are optimized: each index is inserted into the map once (O(log N)) and removed once (O(log N)) throughout the entire BFS.

Space Complexity:
O(N)
The map stores at most N entries. The queue and visited array also take O(N) space.

Optimization Notes:
The solution is largely optimal. Using a std::unordered_map instead of std::map would reduce the logarithmic factor to an average O(1) for map operations, achieving an average time complexity of O(N). However, worst-case for unordered_map is O(N), so std::map offers guaranteed O(log N).

### 💻 Implementation
```cpp
class Solution {
public:
    int minJumps(vector<int>& arr) {
        
        map<int,multiset<int>>m;
        int n=arr.size();
        for(int i=0;i<n;i++){
            m[arr[i]].insert(i);
        }
        queue<int>q;
        q.push(0);
        m[arr[0]]. erase(0);
        vector<int>v(n,0);
        int res=0,s=0;
        while(!q.empty()){
            s=q.size();
            while(s--){
                int c=q.front();
                q.pop();
                if(c==n-1)return res;
                if(c<n-1 and !v[c+1]){
                    m[arr[c+1]].erase(c+1);
                    q.push(c+1);v[c+1]=1;
                }
                if(c and !v[c-1]){
                    v[c-1]=1;
                    m[arr[c-1]].erase(c-1);
                    
                    q.push(c-1);
                }
                for(auto id:m[arr[c]]){
                    if(!v[id]){
                        v[id]=1;
                        m[arr[id]].erase(id);
                        q.push(id);
                    }
                }
            }res++;
        }
        return n;
    }
};
```
