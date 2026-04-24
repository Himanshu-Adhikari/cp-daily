class Solution {
  public:
    int visibleBuildings(vector<int>& arr) {
        int res=0;
        int mx=0;
        for(int i:arr){
            if(i>=mx)res++;
            mx=max(i,mx);
        }
        return res;
    }
};