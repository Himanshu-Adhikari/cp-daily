class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        int n=arr.size();
        int res=0;
        for(int i=0,j=0,c=0;i<n;i++){
            c^=arr[i];
            if(i-j+1==k){res=max(res,c),c^=arr[j++];}
        }
        return res;
    }
};