class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n=arr.size();
        stack<int>s;
        vector<int>res(n,1);
        for(int i=n-1;i>=0;i--){
            while(!s.empty() and arr[s.top()]<arr[i]){
                res[s.top()]=s.top()-i;
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()){res[s.top()]+=s.top();s.pop();}
        return res;
    }
};