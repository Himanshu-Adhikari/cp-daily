class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n=grid[0].size(),m=grid.size();
        vector<vector<int>>pr(m+1,vector<int>(n+1,0));
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                pr[i+1][j+1]=pr[i+1][j]+pr[i][j+1]-pr[i][j]+grid[i][j];
                if(pr[i+1][j+1]<=k)res+=1;
            }
        }
        return res;
    }
};