class Solution {
public:
    #define pi pair<long long,long long>
    #define f first
    #define s second
    
    int maxProductPath(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<pi>>dp(n,vector<pi>(m,{LLONG_MAX,LLONG_MIN}));
        
        dp[0][0]={grid[0][0],grid[0][0]};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i){
                    dp[i][j].s=max({dp[i][j].s,dp[i-1][j].f*1ll*grid[i][j],dp[i-1][j].s*1ll*grid[i][j]});
                    dp[i][j].f=min({dp[i][j].f,dp[i-1][j].f*1ll*grid[i][j],dp[i-1][j].s*1ll*grid[i][j]});
                }
                if(j){
                    dp[i][j].s=max({dp[i][j].s,dp[i][j-1].f*1ll*grid[i][j],dp[i][j-1].s*1ll*grid[i][j]});
                    dp[i][j].f=min({dp[i][j].f,dp[i][j-1].f*1ll*grid[i][j],dp[i][j-1].s*1ll*grid[i][j]});
                }
            }
        }
        
        long long ans=dp[n-1][m-1].s;
        return ans<0?-1:ans%1000000007;
    }
};