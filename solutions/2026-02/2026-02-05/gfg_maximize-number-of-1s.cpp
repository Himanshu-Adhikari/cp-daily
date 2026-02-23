class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        int res=0;
        int i=0;
        int n=arr.size();
        int curr=0,j=0;
        while(i<n){
            if(arr[i]==0)curr+=1;
            while(curr>k and j<=i){
                if(arr[j]==0)curr-=1;
                j+=1;
            }
            res=max(res,i-j+1);
            i++;        
        }
        return res;
    }
};
