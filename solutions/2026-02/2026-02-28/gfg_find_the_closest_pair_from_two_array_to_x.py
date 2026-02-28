class Solution {
  public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        vector<int>res;
        int n=arr1.size(),m=arr2.size();
        int i=0,j=m-1;
        int ni=-1,nj=-1;
        auto rec=[&](int k,int p){
          return abs(x-k-p);  
        };
        while(i<n and j>=0){
            if(ni==-1 or (rec(arr1[ni],arr2[nj])>rec(arr1[i],arr2[j]))){
                ni=i,nj=j;
            }
            if(arr1[i]+arr2[j]<x)i++;
            else j--;
        }
        return {arr1[ni],arr2[nj]}; 
    }
};