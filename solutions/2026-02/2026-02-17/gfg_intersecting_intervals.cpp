class Solution {
  public:
    int overlapInt(vector<vector<int>> &arr) {
        int mx=0;
        for(auto c:arr)mx=max(mx,max(c[0],c[1]));
        vector<int>m(mx+5);
        for(auto& c:arr)m[c[0]]++,m[c[1]+1]--;
        int sm=0,res=0;
        for(auto& b:m){sm+=b;res=max(res,sm);}
        return res;
    }
};
