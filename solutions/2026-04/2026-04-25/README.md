# 📅 Daily CP Solutions — 2026-04-25

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Asteroid Collision
**Platform:** GeeksforGeeks

Problem Insight:
The problem simulates a collision process where numbers with opposite signs interact, with the number having a larger absolute value surviving, or both being removed if absolute values are equal. This reduction continues until no more collisions occur.

Approach:
A stack is utilized to manage the numbers. Each incoming number is compared with the stack's top. If they have opposite signs, they collide. Based on their absolute values, one is removed, the other survives, or both are removed, and the process repeats with the new stack top if the incoming number survives. If signs are same or stack is empty, the number is pushed.

Time Complexity:
O(N)
Each element from the input array is pushed onto the stack at most once and popped at most once.

Space Complexity:
O(N)
In the worst-case scenario, all elements might remain on the stack, requiring linear space.

Optimization Notes:
Optimal. The solution processes each input element in amortized constant time, leading to a linear time complexity which is the minimum required to examine all inputs. The space complexity is also optimal as the stack might need to store all elements.

### 💻 Implementation
```cpp
class Solution {
  public:
    vector<int> reducePairs(vector<int>& arr) {
        // code here
         stack<int> st;

        for (int a : arr) {
            while (!st.empty() && st.top() * a < 0) {
                int b = st.top();
                st.pop();

                if (abs(a) > abs(b)) {
                    // a survives, continue reducing with new top
                    continue;
                }
                else if (abs(a) < abs(b)) {
                    // b survives
                    a = b;
                }
                else {
                    // both removed
                    a = 0;
                }

                break;
            }

            if (a != 0) st.push(a);
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    
    }
};
```

## 🔹 Leetcode Maximize-The-Distance-Between-Points-On-A-Square
**Platform:** LeetCode

Problem Insight:
This problem aims to find the maximum possible minimum distance D between k selected points on the perimeter of a square. Points are mapped to a 1D coordinate system for circular processing.

Approach:
The solution uses binary search on the answer D (the maximum minimum distance). The `check` function determines if a given D is feasible by trying each of the N points as a starting point, then greedily selecting k-1 subsequent points using binary search to maintain the minimum distance D, and finally verifying the circular wrap-around distance.

Time Complexity:
O(N * k * log N * log(Perimeter)) due to N starting points, k greedy steps with log N for bisect_left, and log(Perimeter) for binary search.

Space Complexity:
O(N) for storing the 1D coordinates of the points.

Optimization Notes:
The binary search upper bound (hi) should be side * 2 (half perimeter) for correctness, as the maximum possible distance can exceed 'side'. The `check` function's complexity is O(N * k * log N), which is too slow if k can be O(N); an optimal check function for this problem would be O(N) using a two-pointer technique on an extended array, leading to an overall O(N log(Perimeter)) solution.

### 💻 Implementation
```py
class Solution:
    def maxDistance(self, side: int, points: List[List[int]], k: int) -> int:
        arr = []
        
        for x, y in points:
            if x == 0:
                arr.append(y)
            elif y == side:
                arr.append(side + x)
            elif x == side:
                arr.append(side * 3 - y)
            else:
                arr.append(side * 4 - x)
        
        arr.sort()
        
        def check(limit: int) -> bool:
            perimeter = side * 4
            for start in arr:
                end = start + perimeter - limit
                cur = start
                for _ in range(k - 1):
                    idx = bisect_left(arr, cur + limit)
                    if idx == len(arr) or arr[idx] > end:
                        cur = -1
                        break
                    cur = arr[idx]
                if cur >= 0:
                    return True
            return False
        
        lo, hi = 1, side
        ans = 0
        
        while lo <= hi:
            mid = (lo + hi) // 2
            if check(mid):
                lo = mid + 1
                ans = mid
            else:
                hi = mid - 1
                
        return ans
```
