class Solution {
  public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        queue<int>q;
        vector<int>a(n,0);
        map<int,vector<int>>m;
        for(auto c:prerequisites){a[c[1]]++;m[c[0]].push_back(c[1]);}
        for(int i=0;i<n;i++){
            if(!a[i])q.push(i);
        }
        while(!q.empty()){
            int c=q.front();q.pop();
            for(auto d:m[c]){
                a[d]--;
                if(a[d]==0){
                    q.push(d);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(a[i])return false;
        }
        return true;
    }
};