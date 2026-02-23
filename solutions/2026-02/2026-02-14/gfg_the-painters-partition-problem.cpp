class Solution {
  public:
    int minTime(vector<int>& arr, int k) {
        #define ll long long
        ll l=*max_element(begin(arr),end(arr)),r=accumulate(begin(arr),end(arr),0ll);
        ll res=r;
        int n=arr.size();
        while(l<=r){
            ll md=l+(r-l)/2;
            ll cnt=0;
            ll sm=0;
            int i=0;
            while(i<n){
                sm=0;
                while(i<n and (sm+arr[i])<=md){
                    sm+=arr[i];
                    i+=1;
                }
                cnt+=1;
            }
            if(cnt<=k){res=md,r=md-1;}
            else l=md+1;
        }
        return res;
    }
};