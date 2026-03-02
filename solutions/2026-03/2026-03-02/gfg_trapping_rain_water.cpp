class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int m=0,l=0,r=arr.size()-1,ans=0;
        vector<int>a;
        for(auto c:arr){
            a.push_back(m);
            m=max(m,c);
        }
        for (int i=arr.size()-1,m=0;i>=0;i--){
            ans+=max(min(a[i],m)-arr[i],0);
            m=max(m,arr[i]);
        }
        return ans;
    }
    
};