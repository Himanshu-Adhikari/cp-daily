class Solution {
public:
    // int dp[201][201][1001], f = 0;
    // int rec(int i,int j,int k,vector<vector<int>>&a,int m,int n){
    //     if(i>=m || j>=n || k<0 )return 0;
    //     int cst=(a[i][j]?1:0);
    //     if(i==m-1 && j==n-1){
    //         if((k-cst)>=0){
    //             f=0;
    //             dp[i][j][k]=a[i][j];
    //             return dp[i][j][k];
    //         }
    //     }
    //     int f=a[i][j]+rec(i+1,j,k-cst,a,m,n);
    //     int s=a[i][j]+rec(i,1+j,k-cst,a,m,n);
    //     return dp[i][j][k]=max(f,s);
    // }
    int maxPathScore(vector<vector<int>>& a, int k) {
        int m = a.size(), n = a[0].size();
        // memset(dp, -1, sizeof(dp));
        // f = 0;
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
        int cst = (a[0][0] ? 1 : 0);
        if (cst <= k)
            dp[0][0][cst] = a[0][0];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int p = 0; p <= k; p++) {
                    cst = (a[i][j] ? 1 : 0);
                    if (dp[i][j][p] == -1) continue;
                    if (i < m - 1 and (p + (a[i + 1][j] ? 1 : 0)) <= k) {
                        dp[i + 1][j][p + (a[i + 1][j] ? 1 : 0)] =
                            max(dp[i + 1][j][p + (a[i + 1][j] ? 1 : 0)],
                                dp[i][j][p] + a[i+1][j]);
                    }
                    if (j < n - 1 and (p + (a[i][j + 1] ? 1 : 0)) <= k) {
                        dp[i][j + 1][p + (a[i][1 + j] ? 1 : 0)] =
                            max(dp[i][1 + j][p + (a[i][1 + j] ? 1 : 0)],
                                dp[i][j][p] + a[i][j+1]);
                    }
                }
            }
        }
    
    int res = -1;
    for (int i = 0; i <= k; i++) {
        res = max(res, dp[m - 1][n - 1][i]);
    }
    return res;
}
};