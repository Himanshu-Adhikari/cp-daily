class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        set<int>h(a.begin(),a.end());
        for(int j:b)h.insert(j);
        return vector<int>(begin(h),end(h));
    }
};
