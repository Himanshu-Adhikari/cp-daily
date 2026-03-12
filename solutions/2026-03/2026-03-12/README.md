# 📅 Daily CP Solutions — 2026-03-12

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Maximum K Consecutive Bit Flips
**Platform:** GeeksforGeeks

Problem Insight:
This problem requires a greedy approach. To make all elements 1, we must flip an element if it's currently 0, always choosing to start the K-bit flip at the current index.

Approach:
Iterate through the array, tracking the net effect of previous flips using a queue to manage their end points. If the current element is effectively 0 after considering active flips, perform a new K-bit flip, incrementing the total flip count and updating the active flip status.

Time Complexity:
O(N)
The solution iterates through the array once, and each queue operation takes O(1) time.

Space Complexity:
O(K)
The queue stores the end indices of active flips, which at any given time can be at most K active flips affecting the current window.

Optimization Notes:
The solution is optimal in terms of time complexity. The space complexity can be optimized from O(K) to O(1) by using a fixed-size array or a difference array approach to track active flips instead of a queue, or by directly modifying the input array (if allowed).

### 💻 Implementation
```cpp
class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int cnt = 0, flip = 0;
        queue<int> q;
    
        for (int i = 0; i < n; i++) {
            if (!q.empty() && q.front() == i) {
                q.pop();
                flip ^= 1;
            }
            if ((arr[i] ^ flip) == 0) { // bit is 0 considering flips
                if (i + k > n) return -1;
                cnt++;
                flip ^= 1;
                q.push(i + k);
 
            }
        }
        return cnt;
    }
};
```

## 🔹 Leetcode Maximize-Spanning-Tree-Stability-With-Upgrades
**Platform:** LeetCode

Problem Insight:
This problem asks for the maximum possible minimum edge stability in a spanning tree, allowing up to K stability doublings on optional edges. It's a bottleneck spanning tree problem variant.

Approach:
The solution uses binary search on the answer (the maximum stability). For a given target stability, it checks if a spanning tree can be formed. It prioritizes 'must' edges, then optional edges meeting the target, then optional edges meeting the target with a stability doubling (if K permits). A Disjoint Set Union (DSU) structure tracks connectivity.

Time Complexity:
O(E log E + (N + E) * log(MAX_STABILITY) * alpha(N))
Justification: O(E log E) for initial sorting, plus log(MAX_STABILITY) iterations of binary search, each doing O(N + E * alpha(N)) work (DSU array copy and E DSU operations).

Space Complexity:
O(N + E)
Justification: O(N) for DSU parent array and O(E) for storing and partitioning edges into must/optional lists.

Optimization Notes:
The solution is optimal for this problem. Binary search on the answer combined with a greedy check using DSU is a standard and efficient approach for bottleneck problems with additional constraints like K doublings. No major improvements are apparent given the problem structure.

### 💻 Implementation
```py
class DSU:
    def __init__(self, parent):
        self.parent = parent

    def find(self, x):
        if self.parent[x] == x:
            return x
        self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def join(self, x, y):
        px = self.find(x)
        py = self.find(y)
        self.parent[px] = py


MAX_STABILITY = 200000


class Solution:
    def maxStability(self, n: int, edges: List[List[int]], k: int) -> int:
        ans = -1

        if len(edges) < n - 1:
            return -1

        mustEdges = [e for e in edges if e[3] == 1]
        optionalEdges = [e for e in edges if e[3] != 1]

        if len(mustEdges) > n - 1:
            return -1

        optionalEdges.sort(key=lambda x: x[2], reverse=True)

        selectedInit = 0
        mustMinStability = MAX_STABILITY
        dsuInit = DSU(list(range(n)))

        for u, v, s, must in mustEdges:
            if dsuInit.find(u) == dsuInit.find(v) or selectedInit == n - 1:
                return -1
            dsuInit.join(u, v)
            selectedInit += 1
            mustMinStability = min(mustMinStability, s)

        l = 0
        r = mustMinStability

        while l < r:
            mid = l + ((r - l + 1) >> 1)
            dsu = DSU(dsuInit.parent[:])
            selected = selectedInit
            doubledCount = 0

            for u, v, s, must in optionalEdges:
                if dsu.find(u) == dsu.find(v):
                    continue

                if s >= mid:
                    dsu.join(u, v)
                    selected += 1
                elif doubledCount < k and s * 2 >= mid:
                    doubledCount += 1
                    dsu.join(u, v)
                    selected += 1
                else:
                    break

                if selected == n - 1:
                    break

            if selected != n - 1:
                r = mid - 1
            else:
                ans = l = mid

        return ans
```
