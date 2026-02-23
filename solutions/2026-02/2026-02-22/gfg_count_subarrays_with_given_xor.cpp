class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        #define ll long long
        ll res=0;
        map<ll,ll>m;
        ll curr=0;
        m[0]=1;
        for(int i:arr){
            curr^=i;
            res+=m[curr^k];
            m[curr]++;
        }
        return res;
    }
};