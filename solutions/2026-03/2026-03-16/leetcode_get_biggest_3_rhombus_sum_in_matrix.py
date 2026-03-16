class Solution:
    def getBiggestThree(self, g: List[List[int]]) -> List[int]:
        n,m=len(g),len(g[0])
        s=set()
        for i in range(n):
            for j in range(m):
                s.add(g[i][j])
                k=1
                while i-k>=0 and i+k<n and j-k>=0 and j+k<m:
                    x=i-k;y=j;t=0
                    for d in range(k): t+=g[x+d][y+d]
                    x=i;y=j+k
                    for d in range(k): t+=g[x+d][y-d]
                    x=i+k;y=j
                    for d in range(k): t+=g[x-d][y-d]
                    x=i;y=j-k
                    for d in range(k): t+=g[x-d][y+d]
                    s.add(t)
                    k+=1
        return sorted(s,reverse=True)[:3]