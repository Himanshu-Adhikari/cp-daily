class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        n,m=len(matrix),len(matrix[0])
        for i in range(0,n):
            for j in range(0,i+1):
                matrix[i][j],matrix[j][i]=matrix[j][i],matrix[i][j]
        for i in range(n):
            matrix[i]=matrix[i][::-1]
        