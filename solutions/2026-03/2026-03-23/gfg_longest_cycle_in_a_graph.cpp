class Solution {
public:
    int longestCycle(int V, vector<vector<int>>& edges) {
        vector<int>a(V,-1);
        for(auto &c:edges)a[c[0]]=c[1];
        
        vector<int>vis(V,0);
        int ans=-1;
        
        for(int i=0;i<V;i++){
            if(vis[i])continue;
            
            unordered_map<int,int>mp;
            int nx=i,step=0;
            
            while(nx!=-1 && !vis[nx]){
                vis[nx]=1;
                mp[nx]=step++;
                nx=a[nx];
                
                if(nx!=-1 && mp.count(nx)){
                    ans=max(ans,step-mp[nx]);
                    break;
                }
            }
        }
        return ans;
    }
};