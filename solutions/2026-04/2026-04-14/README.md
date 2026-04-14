# 📅 Daily CP Solutions — 2026-04-14

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Remove Spaces
**Platform:** GeeksforGeeks

Problem Insight:
The problem requires removing all space characters from a given input string. It is a fundamental string processing task.

Approach:
The solution utilizes Python's native string.replace() method. It identifies all occurrences of the space character and substitutes them with an empty string, thereby effectively deleting them.

Time Complexity:
O(N)
The built-in replace method processes the string in a single pass to construct the new string, where N is the input string's length.

Space Complexity:
O(N)
A new string is generated to hold the result, which in the worst case can be the same length, N, as the original string.

Optimization Notes:
This solution is optimal for Python. Python's built-in string methods are highly optimized, often implemented in C, providing the best possible linear time and space complexity for this problem.

### 💻 Implementation
```py
class Solution:
    def removeSpaces(self, s):
        return s.replace(' ','')
```

## 🔹 Leetcode Minimum Total Distance Travelled
**Platform:** LeetCode

Problem Insight:
The problem requires minimizing total distance between houses and factories. Sorting both house and factory locations is key, as the optimal assignment will preserve their relative order.

Approach:
The solution employs dynamic programming with memoization. dp[i][j] represents the minimum total distance to assign houses from index i onwards using factories from index j onwards. At each step, a house a[i] is either assigned to factory b[j], or factory b[j] is skipped for future consideration.

Time Complexity:
O(N * M)
The DP table has N * M states, and each state computation takes constant time. Pre-sorting takes O(N log N + M log M), which is dominated by O(N*M) for the given constraints.

Space Complexity:
O(N * M)
The DP table dp[N][M] is the primary contributor to memory usage.

Optimization Notes:
The solution is optimal for the given constraints where N (houses) is small (up to 100) and M (factory units) can be large (up to 10000). An O(N*M) dynamic programming approach is the standard and most efficient way to solve this class of ordered matching problems.

### 💻 Implementation
```cpp
class Solution {
public:
    #define ll long long
    ll dp[101][10001];
    ll rec(int i,int j,int n,int m,vector<int>&a,vector<int>&b){
        if(i==n)return 0;
        if(j==m)return (LLONG_MAX/2)*1ll;
        if(dp[i][j]!=-1)return dp[i][j];
        ll curr=min(abs(a[i]-b[j])+rec(i+1,j+1,n,m,a,b),rec(i,j+1,n,m,a,b));
        return dp[i][j]=curr;
    }
    long long minimumTotalDistance(vector<int>& a, vector<vector<int>>& f) {
        sort(a.begin(),a.end());
        vector<int>b;
        memset(dp,-1,sizeof(dp));
        for(auto c:f)for(int i=0;i<c[1];i++)b.push_back(c[0]);
        sort(b.begin(),b.end());
        int n=a.size(),m=b.size();
        return rec(0,0,n,m,a,b);
    }
};
```
