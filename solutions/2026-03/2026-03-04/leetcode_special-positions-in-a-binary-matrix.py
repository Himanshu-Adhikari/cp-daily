class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        n,m=len(mat),len(mat[0])
        a,b=[0]*n,[0]*m
        for i in range(n):
            for j in range(m):
                if(mat[i][j]):
                    a[i]+=1
                    b[j]+=1
        res=0
        for i in range(n):
         for  j in range(m):
            if(mat[i][j] and a[i]==1 and b[j]==1):res+=1 
        return res