# 📅 Daily CP Solutions — 2026-04-12

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Toeplitz-Matrix
**Platform:** GeeksforGeeks

Problem Insight:
A Toeplitz matrix requires that all elements along any given top-left to bottom-right diagonal must be identical. This property can be identified by comparing elements based on their (row - column) difference.

Approach:
The solution iterates through each cell (i, j) of the matrix. For each cell, it calculates its diagonal identifier as (i - j) and stores the cell's value in a set associated with that diagonal identifier. Finally, it checks if any diagonal's set contains more than one unique value, which would indicate it is not a Toeplitz matrix.

Time Complexity:
O(N * M * log(max(N, M)))
The solution iterates N*M cells, and for each cell, map access and set insertion take logarithmic time relative to map size (O(log(N+M))) and set size (O(log(min(N,M)))), respectively.

Space Complexity:
O(N * M)
In the worst case (e.g., if many diagonals contain multiple unique values), the map stores entries for all N+M-1 diagonals, and the sum of elements across all sets could be up to N*M.

Optimization Notes:
No, this solution is not optimal. It uses a map and sets, leading to logarithmic factors in time complexity and linear space complexity proportional to N*M. An optimal solution can achieve O(N*M) time and O(1) additional space by simply iterating through the matrix and comparing each element mat[i][j] with its top-left neighbor mat[i-1][j-1] if they exist.

### 💻 Implementation
```cpp
class Solution {
  public:
    bool isToeplitz(vector<vector<int>>& mat) {
        map<int,set<int>>m;
        int n=mat.size(),mn=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<mn;j++){
                m[i-j].insert(mat[i][j]);
            }
        }
        for(auto& [_,a]:m)if(int(a.size())>1)return false;
        return true;
    }
};
```

## 🔹 Leetcode Minimum-Distance-To-Type-A-Word-Using-Two-Fingers
**Platform:** LeetCode

Problem Insight:
This problem asks for the minimum total Manhattan distance for two fingers to type a given word on a fixed keypad layout. It is a classic dynamic programming problem where each character typed requires a decision.

Approach:
The solution uses dynamic programming with memoization. The state is defined by the positions of the two fingers and the index of the next character to type. For each character, the algorithm considers moving either finger 1 or finger 2 to type it, calculating the Manhattan distance cost, and recursively finding the minimum total cost.

Time Complexity:
O(N)
The DP state space is defined by (finger1_pos, finger2_pos, current_index). Finger positions are constant (27 options including unassigned), and current_index ranges from 0 to N-1. Thus, there are 27*27*N states, each taking constant time to compute.

Space Complexity:
O(N)
The DP memoization table (map dp) stores the result for each state. There are 27*27*N possible states, so the space complexity is proportional to N multiplied by a constant factor for the finger positions.

Optimization Notes:
This solution is optimal for the given problem. The DP approach correctly covers all states and transitions, achieving a time complexity linear with the input word length (N) multiplied by a constant factor for the fixed alphabet size. Minor speedups could come from using a 3D array instead of a map for DP, but the fundamental complexity remains the same.

### 💻 Implementation
```cpp
#define pi pair<int,int>
map<char,pi>m;
class Solution {
public:
    tuple<char,char,int> key(char a,char b,int i){
        return make_tuple(a,b,i);
    }
    Solution(){
        if(int(m.size())==0){
            char c='A';
            for(int i=0,f=0;f==0;i++){
                for(int j=0;j<6 and !f;j++){
                    m[c]={i,j};
                    if(c=='Z')f=1;
                    c++;
                }
            }
        }
    }
    map<tuple<char,char,int>,int>dp;
    int rec(char a,char b,int i,string s,int n){
        if(n==i)return 0;
        auto aux=key(a,b,i);
        if(dp.count(aux))return dp[aux];
        int cst=INT_MAX;
        if(a=='!')cst=min(cst,rec(s[i],b,i+1,s,n));
        else cst=min(cst,abs(m[s[i]].first-m[a].first)+abs(m[s[i]].second-m[a].second)+rec(s[i],b,i+1,s,n));
        if(b=='!')cst=min(cst,rec(a,s[i],i+1,s,n));
        else cst=min(cst,abs(m[s[i]].first-m[b].first)+abs(m[s[i]].second-m[b].second)+rec(a,s[i],i+1,s,n));
        return dp[aux]=cst;
    }
    int minimumDistance(string word) {
        int res=0;
        int n=word.size();
        return rec('!','!',0,word,n);
    }

};
```
