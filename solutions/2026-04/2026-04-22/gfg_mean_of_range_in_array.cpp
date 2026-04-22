class Solution {
  public:
    vector<int> findMean(vector<int> &arr, vector<vector<int>> &queries) {
        vector<int>pr,res;
        int sm=0;
        for(auto c:arr){
            sm+=c;
            pr.push_back(sm);
        }
        for(auto c:queries){
            if(c[0]==0)res.push_back(pr[c[1]]/(c[1]-c[0]+1));
            else res.push_back((pr[c[1]]-pr[-1+c[0]])/(c[1]-c[0]+1));
        }
        return res;
    }
};