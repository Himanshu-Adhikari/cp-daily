class Solution {
  public:
    bool isProduct(vector<int>& arr, long long target) {
        #define ll long long
        map<ll,ll>m;
        for(auto c:arr){
            if(c && target%c==0 && m.count(target/c))return true;
            m[c]=1;
            if(c==0 and target ==0)return true;
        }
        return false;
    }
};