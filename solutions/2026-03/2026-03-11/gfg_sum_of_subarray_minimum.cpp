class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
         int n = arr.size();
        stack<int>s;
        vector<int>v(n,-1);
        vector<int>ans(n,0);
        int temp = 0;
        
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]>arr[i]){
                v[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        
        for(int i=0;i<n;i++){
            
            if(v[i]==-1){
                ans[i] = (i+1)*arr[i];
            }
            else{
                int k = i-v[i];
                ans[i]=arr[i]*k;
                ans[i]+=ans[v[i]];
            }
            
            temp+=ans[i];
        }
        
        return temp;
    
    }
};