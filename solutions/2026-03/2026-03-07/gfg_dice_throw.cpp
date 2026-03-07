class Solution {
  public:
    int noOfWays(int m, int n, int x) {
        int a[n+1][x+1];
        memset(a,0,sizeof(a));
        a[n][x]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=m;j++){
                for(int k=0;k<=x-j;k++){
                    a[i][k]+=a[i+1][k+j];
                }
            }
        }
        return a[0][0];
    }
};