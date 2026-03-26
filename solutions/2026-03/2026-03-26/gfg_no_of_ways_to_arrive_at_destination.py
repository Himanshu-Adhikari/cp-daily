class Solution:
    def countPaths(self, V, edges):
        # code here
        MOD = 10**9 + 7
        
        adj = [[] for _ in range(V)]
        for u, v, w in edges:
            adj[u].append((v, w))
            adj[v].append((u, w))
        
        dist = [float('inf')] * V
        ways = [0] * V
        dist[0] = 0
        ways[0] = 1
        pq = [(0, 0)]
        while pq:
            d, u = heapq.heappop(pq)
            if d > dist[u]:
                continue
            for v, w in adj[u]:
                if dist[v] > dist[u] + w:
                    dist[v] = dist[u] + w
                    ways[v] = ways[u]
                    heapq.heappush(pq, (dist[v], v))
                elif dist[v] == dist[u] + w:
                    ways[v] = (ways[v] + ways[u]) % MOD
        
        return ways[V - 1] % MOD
        
        