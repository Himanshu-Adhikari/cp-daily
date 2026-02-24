class Solution {
  public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        int n=a1.size();
        int c=0,res=0;
        vector<int>b;
        for(int i=0;i<n;i++){
            b.push_back(a1[i]-a2[i]);
        }
        map<int,int>m;
        m[0]=-1;
        int sm=0;
        for(int i=0;i<n;i++){
            sm+=b[i];
            if(sm==0)res=max(res,i+1);
            if(m.count(sm))res=max(res,i-m[sm]);
            else m[sm]=i;
        }
        return res;
    }
};