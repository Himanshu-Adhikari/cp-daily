class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& mat) {
        int m=mat.size(),res=0,n=mat[0].size();
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] and mat[i-1][j]){
                    mat[i][j]=1+mat[i-1][j];
                }
            }
        }
        for(int i=0;i<m;i++){
            sort(mat[i].rbegin(),mat[i].rend());
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res=max(res,mat[i][j]*(j+1));
            }
        }
        return res;
    }
};