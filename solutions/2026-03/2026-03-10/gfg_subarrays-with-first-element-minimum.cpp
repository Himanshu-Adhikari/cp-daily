class Solution {
  public:
    int countSubarrays(vector<int> &arr) {
        stack<int>s;
        int n=arr.size();
        vector<int>nx(n,n);
        int res=0;
        for(int i=0;i<n;i++){
            while(!s.empty() and arr[s.top()]>arr[i]){
                nx[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        for(int i=0;i<n;i++){
            res+=(nx[i]-i);
        }
        return res;
    }
};