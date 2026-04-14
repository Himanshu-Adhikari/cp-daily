class Solution {
public:
    #define ll long long
    ll dp[101][10001];
    ll rec(int i,int j,int n,int m,vector<int>&a,vector<int>&b){
        if(i==n)return 0;
        if(j==m)return (LLONG_MAX/2)*1ll;
        if(dp[i][j]!=-1)return dp[i][j];
        ll curr=min(abs(a[i]-b[j])+rec(i+1,j+1,n,m,a,b),rec(i,j+1,n,m,a,b));
        return dp[i][j]=curr;
    }
    long long minimumTotalDistance(vector<int>& a, vector<vector<int>>& f) {
        sort(a.begin(),a.end());
        vector<int>b;
        memset(dp,-1,sizeof(dp));
        for(auto c:f)for(int i=0;i<c[1];i++)b.push_back(c[0]);
        sort(b.begin(),b.end());
        int n=a.size(),m=b.size();
        return rec(0,0,n,m,a,b);
    }
};