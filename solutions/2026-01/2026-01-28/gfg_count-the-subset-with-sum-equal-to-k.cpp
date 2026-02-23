class Solution {
  public:
    unordered_map<string,int>m;
    int rec(int i,int k,vector<int>&arr){
        if(i==arr.size())return k==0;
        string key=to_string(i)+")"+to_string(k);
        if(m.count(key))return m[key];
        return m[key]=rec(i+1,k,arr)+rec(i+1,k-arr[i],arr);
    }
    int countSubset(vector<int> &arr, int k) {
        // code here
        int sm=accumulate(begin(arr),end(arr),0);
        if(sm<k)return 0;
        return rec(0,k,arr);
    }
};