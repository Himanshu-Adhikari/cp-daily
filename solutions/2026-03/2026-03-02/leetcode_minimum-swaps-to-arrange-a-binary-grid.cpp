class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> zeroCount(n,0);
        for(int i = 0; i < n; i++){
            for(int j = n-1; j > 0 && grid[i][j] == 0; j--){
                zeroCount[i]++;
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            int j = i;
            while(j < n && zeroCount[j] < n-i-1){
                j++;
            }
            if(j == n) return -1;
            ans += j-i;
            while(j > i){
                swap(zeroCount[j], zeroCount[j-1]);
                j--;
            }
        }
        return ans;
    }
};