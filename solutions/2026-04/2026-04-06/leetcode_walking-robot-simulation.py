class Solution {
public:
    int robotSim(vector<int>& cmd, vector<vector<int>>& o) {
        int x = 0, y = 0;
        int res = 0, cnt = 0;
        set<pair<int, int>> s;
        
        for (auto& ob : o) {
            s.insert({ob[0], ob[1]});
        }

        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for (auto& c : cmd) {
            if (c == -2) {
                cnt = (cnt + 3) % 4;
            } else if (c == -1) {
                cnt = (cnt + 1) % 4;
            } else {
                for (int i = 0; i < c; ++i) {
                    int nx = x + dirs[cnt].first;
                    int ny = y + dirs[cnt].second;
                    if (s.count({nx, ny})) {
                        break;
                    }
                    x = nx;
                    y = ny;
                    res = max(res, x * x + y * y);
                }
            }
        }
        return res;
    }
};
