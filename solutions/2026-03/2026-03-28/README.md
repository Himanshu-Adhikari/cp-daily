# 📅 Daily CP Solutions — 2026-03-28

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Articulation Point 2
**Platform:** GeeksforGeeks

Problem Insight:
The problem identifies articulation points (cut vertices) in an undirected graph, which are nodes whose removal increases the graph's connected components. This requires tracking discovery times and lowest reachable ancestors during a DFS traversal.

Approach:
The solution uses Depth First Search (DFS) to compute discovery times (tin) and lowest reachable times (low) for each node. A node is an articulation point if it's the root of the DFS tree with more than one child, or if for any child 'it', low[it] >= tin[node] and 'node' is not the root.

Time Complexity:
O(V + E)
The DFS algorithm visits each vertex and edge exactly once, and auxiliary arrays take O(V) time to initialize.

Space Complexity:
O(V + E)
The adjacency list takes O(V + E) space. Auxiliary arrays (vis, tin, low, mark) and the recursion stack take O(V) space.

Optimization Notes:
The solution implements Tarjan's algorithm for finding articulation points, which is the standard and asymptotically optimal approach. No further improvements in time or space complexity are generally possible for this problem.

### 💻 Implementation
```py
class Solution:
      def articulationPoints(self, V, edges):
        def dfs (node, parent):
            vis[node] = 1
            tin[node] = low[node] = timer[0]
            timer[0] += 1
            child = 0
            
            for it in adj[node]:
                if it == parent:
                    continue
                
                if not vis[it]:
                    dfs(it, node)
                    
                    low[node] = min(low[node], low[it])
                    
                    if low[it] >= tin[node] and parent != -1:
                        mark[node] = 1
                        
                    child += 1
                    
                else:
                    low[node] = min(low[node], tin[it])
                    
            if parent == -1 and child > 1:
                mark[node] = 1
                
        
        adj = [[] for _ in range(V)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
            
        vis = [0] * V
        tin = [0] * V
        low = [0] * V
        mark = [0] * V
        timer = [0]
        
        for i in range(V):
            if not vis[i]:
                dfs(i, -1)
                
        ans = []
        for i in range(V):
            if mark[i] == 1:
                ans .append(i)
                
        if len(ans) == 0:
            return [-1]
            
        return ans
```

## 🔹 Leetcode Find The String With Lcp
**Platform:** LeetCode

Problem Insight:
The problem requires reconstructing a string from its LCP (Longest Common Prefix) array. The LCP array defines prefix lengths between all suffix pairs.

Approach:
First, a candidate string is constructed by assigning characters greedily. The first unassigned character gets the next available letter ('a', 'b', etc.). If LCP[i][j] > 0, s[j] is assigned s[i]. Then, the constructed string is verified by checking if it perfectly regenerates the input LCP array, leveraging the recursive property LCP[i][j] = 1 + LCP[i+1][j+1] if s[i] == s[j].

Time Complexity:
O(N^2)
The string construction loop runs N times with an inner loop running N times. The verification step involves two nested loops of N iterations each.

Space Complexity:
O(N)
A character array of size N is used to store the reconstructed string.

Optimization Notes:
The solution is optimal in terms of asymptotic complexity. The input LCP matrix is O(N^2), so any solution processing it will inherently be at least O(N^2). The greedy construction and verification steps are performed within this bound.

### 💻 Implementation
```py
class Solution:
    def findTheString(self, lcp: List[List[int]]) -> str:
        n=len(lcp)
        s:str=[""]*n
        cur=ord('a')
        for i in range(n):
            print("".join(s))
            print(s)
            if(not s[i]):
                if(cur>ord('z')):return ""
                s[i]=chr(cur)
                for j in range(i+1,n):
                    if(lcp[i][j]):
                        s[j]=s[i]
                cur+=1
        for i in range(n-1,-1,-1):
            for j in range(n-1,-1,-1):
                if(s[i]!=s[j]):
                    if(lcp[i][j]):return ""
                else:
                    if i == n - 1 or j == n - 1:
                        if lcp[i][j] != 1:
                            return ""
                    else:
                        if lcp[i][j] != lcp[i + 1][j + 1] + 1:
                            return ""
        return "".join(s)
```
