class Solution {
public:
    int m, n;
    vector<vector<char>> grid;
    int vis[501][501] = {0};
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int nx, ny;
    bool rec(int i, int j, int pi, int pj, char& c) {
        vis[i][j] = 1;
        for (auto d:dir){
            nx=i+d[0],ny=j+d[1];
            if(nx<0 or ny<0 or nx>=m or ny>=n or grid[nx][ny]!=c)continue;
            if(!vis[nx][ny]){
                if(rec(nx,ny,i,j,c))return true;;
            }
            else if(pi!=-1 and pj!=-1 and (nx!=pi or ny!=pj)){
                // cout<<nx<<" "<<ny<<endl;
                // cout<<pi<<" "<<pj<<endl;
                return true;
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        this->grid = grid;
        m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j]) {
                    if (rec(i, j, -1, -1, grid[i][j])){
                        // cout<<grid[i][j]<<" ";
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
