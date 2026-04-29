class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        int n=arr.size();
        int o=accumulate(begin(arr),end(arr),0);
        if(o==0)return -1;
        int res=n;
        for(int i=0,j=0,c=0;i<n;i++){
            c+=arr[i];
            if(i-j+1>o)c-=arr[j++];
            res=min(res,o-c);
        }
        return res;
    }
};