class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int res = 1;
        int k = min(n, m);

        for (int o = 2; o <= k; o++) {
            for (int i = 0; i + o <= n; i++) {
                for (int j = 0; j + o <= m; j++) {
                    vector<int> rows(o, 0), cols(o, 0);
                    int d1 = 0, d2 = 0;

                    for (int r = 0; r < o; r++) {
                        for (int c = 0; c < o; c++) {
                            int v = grid[i + r][j + c];
                            rows[r] += v;
                            cols[c] += v;
                            if (r == c) d1 += v;
                            if (r + c == o - 1) d2 += v;
                        }
                    }

                    int target = rows[0];
                    bool ok = true;

                    for (int r = 0; r < o; r++)
                        if (rows[r] != target) ok = false;

                    for (int c = 0; c < o; c++)
                        if (cols[c] != target) ok = false;

                    if (d1 != target || d2 != target) ok = false;

                    if (ok) res = o;
                }
            }
        }
        return res;
    }
};
