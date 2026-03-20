class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>res(m-k+1,vector<int>(n-k+1));
                set<int>a;
        if(k==1)return res;
        for(int i=0;i<m-k+1;i++){
            for(int j=0;j<n-k+1;j++){
                a.clear();
                for(int x=0;x<k && (i+x)<m;x++){
                    for(int y=0;y<k && (j+y)<n;y++){
                        a.insert(grid[x+i][y+j]);
                        cout<<grid[x+i][y+j]<<" ";
                    }
                }
                cout<<endl;
                int t=0,pr,cr=INT_MAX;
                for(auto c:a){
                   if(t==0)t=1;
                   else cr=min(cr,abs(pr-c));
                   pr=c;
                }
                if(cr==INT_MAX)res[i][j]=0;
                else res[i][j]=cr;
            }
        }
        return res;
    }
};