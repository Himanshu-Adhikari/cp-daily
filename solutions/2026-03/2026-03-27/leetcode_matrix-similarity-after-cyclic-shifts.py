class Solution:
    def areSimilar(self, mat: List[List[int]], k: int) -> bool:
        n,m=len(mat),len(mat[0])
        k=k%m
        res=True
        for i in range(n):
            for j in range(m):
                if(mat[i][j]!=mat[i][(j+k)%m]):return False
        return True