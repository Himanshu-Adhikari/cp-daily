class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        vector<int>res;
        int n=arr.size();
        multiset<int>m;
        for(int i=0,j=0;i<n;i++){
            m.insert(arr[i]);
            if((i-j+1)==k){
                res.push_back(*m.rbegin());
                m.erase(m.find(arr[j++]));
            }
        }
        return res;
    }
};