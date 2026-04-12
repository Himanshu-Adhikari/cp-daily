class Solution {
  public:
    bool isToeplitz(vector<vector<int>>& mat) {
        map<int,set<int>>m;
        int n=mat.size(),mn=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<mn;j++){
                m[i-j].insert(mat[i][j]);
            }
        }
        for(auto& [_,a]:m)if(int(a.size())>1)return false;
        return true;
    }
};