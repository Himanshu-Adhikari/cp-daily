class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = 12345;
        int rows = grid.size();
        int cols = grid[0].size();
        int n = rows * cols;
        
        vector<vector<int>> res(rows, vector<int>(cols, 0));
        vector<int> t;
        
        for (auto row : grid) {
            for (auto val : row) {
                t.push_back(val % m);
            }
        }
        
        vector<int> pre(n, 1), suf(n, 1);
        
        for (int i = 1; i < n; i++) {
            pre[i] = (pre[i - 1] * t[i - 1]) % m;
        }
        
        int c = 1;
        
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = (c * suf[i]) % m;
            c = (c * t[i]) % m;
        }
        
        int r = 0; c = 0;
        
        for (int i = 0; i < n; i++) {
            res[r][c] = (pre[i] * suf[i]) % m;
            c++;
            if (c == cols) {
                r++;
                c = 0;
            }
        }
        
        return res;
    }
};
