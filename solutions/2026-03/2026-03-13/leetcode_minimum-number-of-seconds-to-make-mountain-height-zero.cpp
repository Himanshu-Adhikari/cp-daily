class Solution {
public:
    #define ll long long
    ll pec(ll i,ll m,int a){
        ll l=0,r=1e6,curr=0;
        while(l<=r){
            ll md=l+(r-l)/2;
            if(((md*(md+1)/2)*i) <= m)curr=md,l=md+1;
            else r=md-1;
        }
        return curr;
    }
    bool rec(ll m,int a,vector<int>&b){
        ll cnt=0;,,
        for(auto c:b){
            cnt+=1ll*pec(1ll*c,m,a);
        }
        // cout<<m<<" "<<cnt<<endl;
        return cnt>=a;
    }
    long long minNumberOfSeconds(int a, vector<int>& b) {
        ll res=1ll*a*(a+1)*b[0]/2;
        int n=b.size();
        ll l=0,r=1e9;
        while(l<=r){
            ll md=l+(r-l)/2;
            if(rec(md,a,b))res=md,r=md-1;
            else l=md+1;
        }
        return res;
    }
};