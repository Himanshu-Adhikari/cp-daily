class Solution:
    def findRotation(self, mat: List[List[int]], target: List[List[int]]) -> bool:
        n=len(mat)
        if(mat==target):return True
        for i in range(3):
            mat=[[mat[i][j] for i in range(n-1,-1,-1)] for j in range(n)]
            if(mat==target):
                return True
        return False