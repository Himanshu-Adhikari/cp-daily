class Solution {
public:
    vector<pair<int,int>> dir = {
        {0,1},{1,0},{-1,0},{0,-1}
    };

    bool dfs(int i, int j, int k,
             vector<vector<char>>& mat, string& w) {
        if (k == w.size()) return true;
        if (i<0 || j<0 || i>=mat.size() || j>=mat[0].size()
            || mat[i][j] != w[k]) return false;
        char t = mat[i][j];
        mat[i][j] = '#';
        for (auto [x,y] : dir)
            if (dfs(i+x, j+y, k+1, mat, w)) return mat[i][j]=t, true;
        mat[i][j] = t;
        return false;
    }

    bool isWordExist(vector<vector<char>>& mat, string word) {
        for (int i=0;i<mat.size();i++)
            for (int j=0;j<mat[0].size();j++)
                if (mat[i][j]==word[0] && dfs(i,j,0,mat,word))
                    return true;
        return false;
    }
};
