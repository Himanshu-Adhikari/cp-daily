class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int maxDist = -1;
        for(int i = 0; i < n; i++){
            for(int j = n - 1; j > i; j--){
                if(colors[i] != colors[j]){
                    maxDist = max(maxDist, j - i);
                    break;
                }
            }
        }
        return maxDist;
    }
};
