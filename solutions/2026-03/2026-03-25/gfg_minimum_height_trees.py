class Solution:
    def minHeightRoot(self, V, edges):
        gr=[[] for i in range(V)]
        ind=[0]*V
        for i in edges:
            gr[i[0]].append(i[1])
            gr[i[1]].append(i[0])
            ind[i[0]]+=1
            ind[i[1]]+=1
        res=[]
        q=[]
        for i in range(V):
            if(ind[i]==1):
                q.append(i)
        while(q):
            res=[]
            s=len(q)
            while(s):
                c=q.pop(0)
                res.append(c)
                for i in gr[c]:
                    ind[i]-=1
                    if(ind[i]==1):
                        q.append(i)
                s-=1
        return res
        
