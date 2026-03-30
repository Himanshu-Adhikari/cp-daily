# 📅 Daily CP Solutions — 2026-03-30

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Minimum-Cost-To-Connect-All-Houses-In-A-City
**Platform:** GeeksforGeeks

Problem Insight:
The problem asks for the minimum cost to connect all houses, which is a classic Minimum Spanning Tree (MST) problem. Edge weights are defined by the Manhattan distance between house coordinates.

Approach:
The solution generates all possible pairwise connections (edges) between houses along with their Manhattan distances. These edges are then sorted by cost. Finally, Kruskal's algorithm, implemented with a Disjoint Set Union (DSU) data structure, is used to build the MST by iteratively adding the cheapest available edge that connects two previously disconnected components.

Time Complexity:
O(N^2 log N)
Generating all N*(N-1)/2 edges takes O(N^2). Sorting these O(N^2) edges takes O(N^2 log(N^2)) which simplifies to O(N^2 log N). Kruskal's algorithm with DSU runs in effectively O(E alpha(N)) time, where E is the number of edges (O(N^2)) and alpha is the inverse Ackermann function, making it dominated by the sorting step.

Space Complexity:
O(N^2)
Storing all N*(N-1)/2 edges requires O(N^2) space. The parent array for DSU requires O(N) space.

Optimization Notes:
The solution is an optimal implementation of Kruskal's algorithm on a complete graph with N nodes. However, for geometric MST problems with Manhattan distance, it's possible to avoid generating all O(N^2) edges. Advanced techniques like a plane sweep algorithm can be used to identify only O(N log N) "relevant" edges that might be part of the MST. Applying Kruskal's on this sparse graph would reduce the total time complexity to O(N log N).

CODE:

### 💻 Implementation
```py
class Solution:
    def minCost(self, houses):
        n = len(houses)
        
        edges = []
        for i in range(n):
            x1, y1 = houses[i]
            for j in range(i + 1, n):
                x2,y2 = houses[j]
                cost = abs(x1 - x2) + abs(y1 - y2)
                edges.append((cost, i, j))
                
        edges.sort()
        
        parent = list(range(n))
        
        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
                
            return parent[x]
            
        def union(x, y):
            px, py = find(x), find(y)
            if px != py:
                parent[py] = px
                return True
            return False
            
        total_cost = 0
        edges_used = 0
        
        for cost, u, v in edges:
            if union(u, v):
                total_cost += cost
                edges_used += 1
                if edges_used == n - 1:
                    break
        return total_cost


```

## 🔹 Leetcode Check-If-Strings-Can-Be-Made-Equal-With-Operations-Ii
**Platform:** LeetCode

Problem Insight:
The problem checks if two strings are equivalent by allowing character swaps only within even positions and only within odd positions. This means the multisets of characters for even and odd positions must be identical for both strings.

Approach:
The solution separates characters from each string into two groups: those at even indices and those at odd indices. It then sorts these four resultant groups and compares the sorted lists of characters for corresponding even and odd groups.

Time Complexity:
O(N log N). Building substrings is O(N), and sorting substrings of length N/2 takes O(N log N) for each of the four sorts.

Space Complexity:
O(N). Four new strings are created, each potentially storing N/2 characters.

Optimization Notes:
It is not optimal. Time can be improved to O(N) and space to O(1) by using frequency arrays (e.g., size 26 for lowercase letters) to count characters at even and odd positions instead of building and sorting substrings.

### 💻 Implementation
```py
class Solution:
    def checkStrings(self, s1: str, s2: str) -> bool:
        a1,a2,b1,b2="","","",""
        n=len(s1)
        for i in range(n):
            if(i%2):
                a1+=s1[i]
                b1+=s2[i]
            else:
                a2+=s1[i]
                b2+=s2[i]
        return sorted(a1)==sorted(b1) and sorted(a2)==sorted(b2)

```
