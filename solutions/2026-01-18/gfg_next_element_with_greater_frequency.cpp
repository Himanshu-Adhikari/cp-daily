class Solution {
  public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        map<int,int>m;
        int n=arr.size();
        vector<int>res(n,-1);
        for(int i:arr)m[i]++;
        stack<int>s;
        for(int i=0;i<n;i++){
            while(!s.empty() and m[arr[i]]>m[arr[s.top()]]){
                res[s.top()]=arr[i];
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};
