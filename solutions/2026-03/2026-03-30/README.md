# 📅 Daily CP Solutions — 2026-03-30

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Minimum-Cost-To-Connect-All-Houses-In-A-City
**Platform:** GeeksforGeeks

Problem Insight:
The problem asks for the minimum cost to connect all houses, which is a classic Minimum Spanning Tree (MST) problem where edge costs are Manhattan distances.

Approach:
The solution applies Kruskal's algorithm. It first generates all possible edges between houses with Manhattan distance as cost, then sorts these edges by cost. A Disjoint Set Union (DSU) data structure is used to efficiently add edges to the MST if they connect two previously unconnected components, accumulating the total cost until n-1 edges are added.

Time Complexity:
O(N^2 log N) because generating all N^2 edges takes O(N^2), and sorting them dominates with O(N^2 log(N^2)) which simplifies to O(N^2 log N). The DSU operations are near-constant time.

Space Complexity:
O(N^2) because all N^2 possible edges are stored explicitly in a list. The parent array for DSU takes O(N) space.

Optimization Notes:
The solution is optimal for a general graph where all N^2 edges must be considered. For a geometric problem like this, if N were extremely large (e.g., 10^5 or more), specialized geometric MST algorithms or data structures (like a Delaunay triangulation or K-d tree to find nearest neighbors) could achieve faster times (e.g., O(N log N) or O(N log^2 N)) by avoiding explicit construction of all N^2 edges. However, for typical competitive programming constraints where N is up to a few thousand, O(N^2 log N) is a standard and efficient approach.

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
Characters at even indices can only be swapped with other even-indexed characters, and similarly for odd indices. This implies independent multisets for even and odd positions.

Approach:
The solution separates characters from s1 and s2 into two distinct groups based on their index parity (even or odd). It then compares the character multisets for corresponding parities by sorting the separated character strings and checking for equality.

Time Complexity:
O(N^2)
String concatenations in a loop take O(N^2) time, dominating the O(N log N) time for sorting the resulting strings.

Space Complexity:
O(N)
Four new strings are created to store characters from s1 and s2, each holding roughly N/2 characters. Temporary space for sorting is also O(N).

Optimization Notes:
The solution is not optimal. It can be improved to O(N) time complexity by using frequency arrays (or character counts) instead of building and sorting new strings. This eliminates the O(N^2) concatenation cost and the O(N log N) sorting cost, replacing them with O(N) for counting and O(1) for comparing counts.

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
