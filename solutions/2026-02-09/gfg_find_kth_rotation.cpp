class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int mn=*min_element(begin(arr),end(arr));
        int n=arr.size();
        for(int i=0;i<n;i++)if(arr[i]==mn)return i;
        return n;
    }
};
