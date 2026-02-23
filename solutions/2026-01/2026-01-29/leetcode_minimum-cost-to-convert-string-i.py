class Solution:
    def minimumCost(self, source: str, target: str, original: List[str], changed: List[str], cost: List[int]) -> int:
        mp=[[float('inf')]*26 for j in range(26)]
        n=len(cost)
        for i in range(n):
            x,y=ord(original[i])-ord('a'),ord(changed[i])-ord('a')
            mp[x][y]=min(mp[x][y],cost[i])
        res=0
        for k in range(26):
            for i in range(26):
                for j in range(26):
                    if(mp[i][k]!=float('inf') and mp[k][j]!=float('inf')):
                        mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j])
                    if(i==j):mp[i][j]=0
        for s,t in zip(source,target):
            x=ord(s)-ord('a')
            y=ord(t)-ord('a')
            if(x!=y and mp[x][y]==float('inf')):
                return -1
            res+=mp[x][y]
        return res
