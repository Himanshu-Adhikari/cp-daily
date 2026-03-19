class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int a[1001][1001][2]={0};
        int n=grid.size(),m=grid[0].size(),res=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                a[i][j][0]=a[i-1][j][0]+a[i][j-1][0]+(grid[i-1][j-1]=='X')-a[i-1][j-1][0];
                a[i][j][1]=a[i-1][j][1]+a[i][j-1][1]+(grid[i-1][j-1]=='Y')-a[i-1][j-1][1];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                res=res+(a[i][j][0] && a[i][j][0]==a[i][j][1]);
            }
        }
        return res;
    }
};