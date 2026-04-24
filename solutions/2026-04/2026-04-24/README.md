# 📅 Daily CP Solutions — 2026-04-24

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Buildings Recieving Sunlight
**Platform:** GeeksforGeeks

Problem Insight:
The problem counts buildings visible from the left, where a building is visible if its height is greater than or equal to the maximum height of all preceding buildings.

Approach:
The solution iterates through the buildings from left to right, keeping track of the maximum height encountered so far. If the current building's height is greater than or equal to this running maximum, it is counted as visible, and the maximum height is updated.

Time Complexity:
O(N) where N is the number of buildings. The algorithm performs a single pass through the input array, doing constant work for each element.

Space Complexity:
O(1) constant extra space. Only a few integer variables are used to store the count and the maximum height.

Optimization Notes:
The solution is optimal. It processes each building exactly once with constant time operations, making it impossible to solve with a lower time complexity as all buildings must be inspected.

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
The goal is to find the maximum possible absolute final position by replacing each '_' with either 'L' or 'R'. This involves determining the two extreme possible final positions (most left and most right).

Approach:
Iterate through the moves string, tracking counts of 'L', 'R', and '_'. Calculate two potential final positions: one where all '_' resolve to extend movement in the 'R' direction, and another where all '_' resolve to extend movement in the 'L' direction. The maximum absolute distance is found by taking the maximum of these two resulting positions (adjusted for direction).

Time Complexity:
O(N)
A single pass is made through the input string of length N.

Space Complexity:
O(1)
Only a fixed number of integer variables are used regardless of input size.

Optimization Notes:
It is optimal. The solution processes the input string in a single pass and uses constant extra space, achieving the best possible asymptotic complexity.

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
