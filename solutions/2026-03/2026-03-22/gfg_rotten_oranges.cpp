class Solution {
  public:
    int orangesRot(vector<vector<int>>& mat) {
        queue<pair<int,int>>q;
        int n=mat.size(),m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==2)q.push({i,j});
            }
        }
        vector<pair<int,int>>d={{0,1},{1,0},{-1,0},{0,-1}};
        int res=0;
        while(!q.empty()){
            int s=q.size();
            while(s--){
                auto[x,y]=q.front();q.pop();
                for(auto [i,j]:d){
                    int nx=i+x,ny=y+j;
                    if(nx<0 or nx>=n or ny<0 or ny>=m or mat[nx][ny]!=1)continue;
                    mat[nx][ny]=2;
                    q.push({nx,ny});
                }
            }
            if(q.size())res+=1;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1)return -1;
            }
        }
        return res;
    }
};