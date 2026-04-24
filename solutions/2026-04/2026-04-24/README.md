# 📅 Daily CP Solutions — 2026-04-24

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Buildings Recieving Sunlight
**Platform:** GeeksforGeeks

Problem Insight:
Counts buildings visible from the left side. A building is visible if it is taller than or equal to any building to its left.

Approach:
The solution iterates through the buildings from left to right. It maintains a running maximum height encountered so far. If a building's height is greater than or equal to this maximum, it is considered visible and counted.

Time Complexity:
O(N) where N is the number of buildings. The solution involves a single pass through the input array.

Space Complexity:
O(1). The solution uses a constant number of extra variables regardless of input size.

Optimization Notes:
The solution is optimal. It requires visiting each building at least once (O(N) time) and uses constant auxiliary space (O(1)), achieving the best possible complexity for this problem.

### 💻 Implementation
```cpp
class Solution {
  public:
    int visibleBuildings(vector<int>& arr) {
        int res=0;
        int mx=0;
        for(int i:arr){
            if(i>=mx)res++;
            mx=max(i,mx);
        }
        return res;
    }
};
```

## 🔹 Leetcode Furthest-Point-From-Origin
**Platform:** LeetCode

Problem Insight:
The goal is to find the maximum possible absolute distance from the origin. Unknown moves ('_') can be chosen to maximize this distance.

Approach:
The solution calculates two extreme final positions: one by treating all '_' as 'L' (yielding a position P_min) and another by treating all '_' as 'R' (yielding a position P_max). The final answer is the maximum of the absolute values of these two positions. The code's variables 'l' and 'r' effectively compute -P_min and P_max respectively, and then take their maximum.

Time Complexity:
O(N)
The solution iterates through the input string of length N exactly once.

Space Complexity:
O(1)
Only a fixed number of integer variables are used regardless of input size.

Optimization Notes:
The solution is optimal. It processes each character of the input string exactly once, achieving O(N) time complexity, and uses a constant amount of extra memory, achieving O(1) space complexity. No further algorithmic improvements are possible.

### 💻 Implementation
```cpp
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l=0,r=0;for(auto c:moves)l+=(c=='_' || c=='L') -(c=='R'),r+=(c=='_' || c=='R') - (c=='L');
        return max(l,r);
    }
};
```
