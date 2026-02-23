class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        vector<int>res;
        set<int>a(begin(arr),end(arr));
        for(int i=low;i<=high;i++)if(!a.count(i))res.push_back(i);
        return res;
    }
};