# 📅 Daily CP Solutions — 2026-02-17

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Intersecting Intervals
**Platform:** GeeksforGeeks

Problem Insight:
The problem seeks to find the maximum number of intervals that overlap at any single point in time. This is a classic sweep-line problem.

Approach:
The solution employs a difference array to track changes in interval overlaps. It marks interval start points with an increment (+1) and points just after interval ends with a decrement (-1), then computes prefix sums to find the peak overlap.

Time Complexity:
O(N + K) where N is the number of intervals and K is the maximum coordinate value. It iterates through N intervals to update the difference array and then iterates up to K positions to calculate prefix sums.

Space Complexity:
O(K) where K is the maximum coordinate value. A difference array of size proportional to the maximum coordinate value is created.

Optimization Notes:
The solution is optimal if the maximum coordinate value K is not excessively large. If K is very large (e.g., 10^9), the space and time complexity become dominated by K. In such cases, a sweep-line algorithm using a sorted list of events or coordinate compression would be more optimal, achieving O(N log N) time and O(N) space.

### 💻 Implementation
```cpp
class Solution {
  public:
    int overlapInt(vector<vector<int>> &arr) {
        int mx=0;
        for(auto c:arr)mx=max(mx,max(c[0],c[1]));
        vector<int>m(mx+5);
        for(auto& c:arr)m[c[0]]++,m[c[1]+1]--;
        int sm=0,res=0;
        for(auto& b:m){sm+=b;res=max(res,sm);}
        return res;
    }
};

```

## 🔹 Leetcode Binary Watch
**Platform:** LeetCode

Problem Insight:
The problem involves finding all valid times on a binary watch given a specific number of lit LEDs. It effectively translates to counting set bits for hour and minute values that sum to the target.

Approach:
The solution iterates through all possible hour and minute combinations within their valid ranges. For each combination, it counts the number of set bits (lit LEDs) for both the hour and minute values. If the total count matches the given 'turnedOn' value, the time is formatted and added to the result list.

Time Complexity:
O(1)
The loops run a fixed number of times (12 hours * 60 minutes), and bit counting for small numbers is constant time.

Space Complexity:
O(1)
The number of possible output strings is constant and small (at most 49 times for a binary watch), independent of the input 'turnedOn'.

Optimization Notes:
The solution is optimal for this problem. The search space of 12 hours * 60 minutes (720 total times) is extremely small, making a brute-force approach highly efficient and practical. More complex algorithms would offer no asymptotic or practical improvement.

### 💻 Implementation
```py
class Solution:
    def readBinaryWatch(self, turnedOn: int) -> List[str]:
        ans = list()
        for h in range(12):
            for m in range(60):
                if bin(h).count("1") + bin(m).count("1") == turnedOn:
                    ans.append(f"{h}:{m:02d}")
        return ans
```
