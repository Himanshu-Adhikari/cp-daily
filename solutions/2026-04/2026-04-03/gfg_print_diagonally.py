class Solution:
    def diagView(self, mat): 
       res=[]
       n,m=len(mat),len(mat[0])
       for j in range(0,m):
           i,k=0,j
           while(i<n and j>=0):
               res.append(mat[i][j])
               i+=1
               j-=1
       for i in range(1,n):
            k,j=i,m-1
            while(k<n and j>=0):
               res.append(mat[k][j])
               k+=1
               j-=1
       return res