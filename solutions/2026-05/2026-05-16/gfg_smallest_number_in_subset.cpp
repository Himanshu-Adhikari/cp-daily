class Solution {
  public:
    int findSmallest(vector<int> &arr) {
        sort(begin(arr),end(arr));
        int cnt=1;
        int sm=0;
        for(auto c:arr){
            if(c>cnt)return cnt;
            cnt+=c;
        }
        return cnt;
    }
};