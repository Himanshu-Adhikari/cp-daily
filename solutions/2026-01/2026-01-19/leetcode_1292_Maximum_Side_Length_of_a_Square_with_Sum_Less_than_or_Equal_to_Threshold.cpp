class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> a(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                a[i + 1][j + 1] = mat[i][j] + a[i + 1][j] + a[i][j + 1] - a[i][j];

        auto ok = [&](int sz) {
            for (int i = 0; i + sz <= m; i++) {
                for (int j = 0; j + sz <= n; j++) {
                    int s = a[i + sz][j + sz]
                          - a[i][j + sz]
                          - a[i + sz][j]
                          + a[i][j];
                    if (s <= threshold) return true;
                }
            }
            return false;
        };

        int l = 0, r = min(m, n), res = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (ok(mid)) res = mid, l = mid + 1;
            else r = mid - 1;
        }
        return res;
    }
};
