class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n=grid.size(),m=grid[0].size();
        int ik=x+k-1;
        while(x<ik){
            for(int i=y;i<y+k;i++){
                swap(grid[x][i],grid[ik][i]);
            }
            x++,ik--;
        }
        return grid;
    }
};