# 📅 Daily CP Solutions — 2026-04-25

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Asteroid Collision
**Platform:** GeeksforGeeks

Problem Insight:
The problem involves reducing a sequence of integers based on their signs and absolute values, where elements with opposite signs can "collide" and be removed or modified. This simulates a process like asteroid collision.

Approach:
A stack is used to process the integers from left to right. If an incoming integer encounters an element on top of the stack with an opposite sign, they collide. The collision rules are: if absolute value of incoming is greater, the stack top is removed and incoming continues colliding; if less, incoming is removed; if equal, both are removed. If no collision, the integer is pushed.

Time Complexity:
O(N)
Each element is pushed onto the stack at most once and popped from the stack at most once.

Space Complexity:
O(N)
In the worst case, all elements can be stored in the stack or the final result vector.

Optimization Notes:
The solution is optimal. It achieves linear time complexity because each element is processed in amortized constant time. Linear space complexity is also optimal as the result itself can contain up to N elements.

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
This solution aims to find the maximum possible minimum distance between k selected points on a square's perimeter. It converts 2D coordinates to 1D distances, sorts them, and uses binary search on the answer.

Approach:
Points are mapped to their 1D positions along the perimeter, then sorted. A binary search determines the maximum minimum distance (limit). The check function, for a given limit, greedily attempts to select k points, each at least 'limit' distance from the previous, but its wrap-around logic for intermediate points is incomplete, treating the array as mostly linear.

Time Complexity:
O(N log N + N * K * log N * log P) where N is the number of points, K is the count of points to select, and P is the perimeter length.
Sorting takes O(N log N). Binary search performs log P iterations. Each check function call iterates N times, performing K bisect_left calls, resulting in O(N * K * log N).

Space Complexity:
O(N) for storing the 1D distances.

Optimization Notes:
The check function's time complexity is O(N * K * log N), which can be improved to O(N) by using a two-pointer approach on a conceptually doubled array to efficiently find the next point and handle circularity for all points, not just the final one. The binary search upper bound (hi) should be the total perimeter (4 * side) instead of just 'side' to correctly cover the full range of possible distances. The current check function is flawed as it does not correctly handle intermediate points that might wrap around the perimeter.

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
