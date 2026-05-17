# 📅 Daily CP Solutions — 2026-05-17

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Make The Array Beautiful
**Platform:** GeeksforGeeks

Problem Insight:
This problem requires reducing an array by repeatedly removing adjacent elements with opposite signs. The objective is to return the resulting array while maintaining the relative order of the remaining elements.

Approach:
The solution uses two conceptual stacks, represented by vectors 'p' for positive indices and 'n' for negative indices. It iterates through the input array, pushing an element's index onto its corresponding stack if it cannot cancel a previously encountered element of opposite sign from the other stack. If cancellation is possible, the top of the opposite stack is removed. Finally, the remaining indices from both stacks are merged in sorted order to construct the final array, preserving relative order.

Time Complexity:
O(N)
The initial loop processes each element once with amortized O(1) vector operations. The final merge of indices takes O(N) time.

Space Complexity:
O(N)
In the worst case, all elements might remain, requiring 'p' and 'n' vectors to store up to O(N) indices combined, and 'res' to store O(N) elements.

Optimization Notes:
The solution is optimal in terms of time and space complexity. It processes each element a constant number of times and uses linear extra space. A single stack approach directly storing values and then reversing the result is an alternative that achieves the same optimal complexity and might be slightly more concise.

### 💻 Implementation
```cpp
class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        vector<int>p,n,res;
        int nm=arr.size();
        for(int i=0;i<nm;i++){
            if(arr[i]>=0){
                if(int(n.size())){
                    n.pop_back();
                }
                else{
                    p.push_back(i);
                }
            }
            else{
                
                if(int(p.size()) ){
                    p.pop_back();
                }
                else{
                    n.push_back(i);
                }
            }
        }
        vector<int>po;
        for(auto c:p)po.push_back(c);
        for(auto c:n)po.push_back(c);
        int i=0,j=0;
        int fn=p.size(),sn=n.size();
        while(i<fn && j<sn){
            if(p[i]<n[j])res.push_back(arr[p[i++]]);
            else res.push_back(arr[n[j++]]);
        }
        while(i<fn)res.push_back(arr[p[i++]]);
        while(j<sn)res.push_back(arr[n[j++]]);
        return res;
    }
};
```

## 🔹 Leetcode Jump Game Iii
**Platform:** LeetCode

Problem Insight:
This problem is a graph traversal task where array indices are nodes and jumps define edges. The goal is to determine if an index with value 0 is reachable from a given starting index.

Approach:
The solution employs a Breadth-First Search (BFS) to explore reachable indices. It maintains a queue for indices to visit and a visited array to prevent cycles and redundant processing. If an index with value 0 is encountered, it immediately returns true.

Time Complexity:
O(N)
Each array index (node) is pushed to the queue and processed at most once.

Space Complexity:
O(N)
The queue can store up to N indices, and the 'v' vector uses N space for visited tracking.

Optimization Notes:
The solution is optimal. BFS guarantees finding the shortest path to a zero-value node if one exists, exploring each reachable index at most once, resulting in linear time and space complexity which cannot be improved upon.

### 💻 Implementation
```cpp
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int>q;
        int n=arr.size();vector<int>v(n,0);
        q.push(start);
        while(!q.empty()){
            int c=q.front();q.pop();
            v[c]=1;
            if(!arr[c])return true;
            if(c+arr[c]<n and !v[c+arr[c]])q.push(c+arr[c]);
            if(c>=arr[c] and !v[c-arr[c]])q.push(c-arr[c]);
        }
        return false;
    }
};
```
