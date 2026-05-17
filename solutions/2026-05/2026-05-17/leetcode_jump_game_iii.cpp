class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int>q;
        int n=arr.size();vector<int>v(n,0);
        q.push(start);
        while(!q.empty()){
            int c=q.front();q.pop();
            v[c]=1;
            if(!arr[c])return true;
            if(c+arr[c]<n and !v[c+arr[c]])q.push(c+arr[c]);
            if(c>=arr[c] and !v[c-arr[c]])q.push(c-arr[c]);
        }
        return false;
    }
};