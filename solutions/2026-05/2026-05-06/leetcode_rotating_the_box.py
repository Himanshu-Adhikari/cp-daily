class Solution:
    def rotateTheBox(self, g: List[List[str]]) -> List[List[str]]:
        n,m=len(g),len(g[0])
        res=[['.' for i in range(n)] for j in range(m)]
        for i in range(n):
            c=m-1
            for j in range(m-1,-1,-1):
                if(g[i][j]=='#'):
                    res[c][n-1-i]='#'
                    c-=1
                elif(g[i][j]=='*'):
                    res[j][n-1-i]='*'
                    c=j-1
        return res