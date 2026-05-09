class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k)
    {
        int n=grid.size();
        int m=grid[0].size();
        int R1=0,C1=0,R2=n-1,C2=m-1;
        while(R1<R2 && C1<C2)
        {
            vector<int>res;
            for (int j=C1;j<=C2;j++)res.push_back(grid[R1][j]);
            for (int i=R1+1;i<=R2;i++)res.push_back(grid[i][C2]);
            for (int j=C2-1;j>=C1;j--)res.push_back(grid[R2][j]);
            for (int i=R2-1;i>=R1+1;i--)res.push_back(grid[i][C1]);
           int r=0,mn=res.size();
            for (int j=C1;j<=C2;j++)grid[R1][j]=res[((r++)+k)%mn];
            for (int i=R1+1;i<=R2;i++)grid[i][C2]=res[((r++)+k)%mn];
            for (int i=C2-1;i>=C1;i--)grid[R2][i]=res[((r++)+k)%mn];
            for (int i=R2-1;i>=R1+1;i--)grid[i][C1]=res[((r++)+k)%mn];
            R1++;C1++;R2--;C2--;
        }
        return grid;

    }
};
