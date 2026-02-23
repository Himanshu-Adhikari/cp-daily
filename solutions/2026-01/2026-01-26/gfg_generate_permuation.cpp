class Solution {
  public:
    vector<vector<int>> permuteDist(vector<int>& arr) {
        sort(begin(arr),end(arr));
        vector<vector<int>>res;
        do{
            res.push_back(arr);
        }while(next_permutation(begin(arr),end(arr)));
        return res;
    }
};