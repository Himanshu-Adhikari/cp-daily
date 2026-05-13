class Solution {
  public:
  
    void firstDfs(int node, vector<int>adj[], vector<bool>&vis, 
    stack<int>&st){
        vis[node]=1;
        for(auto &it:adj[node]){
            if(!vis[it]) firstDfs(it, adj, vis, st);
        }
        st.push(node);
    }
    
    void dfs(int node, vector<int>adj[], vector<bool>&vis){
        vis[node]=1;
        for(auto &it:adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis);
            }
        }
    }
  
    int findMotherVertex(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>adj[V];
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }
        
        stack<int>st;
        
        vector<bool>vis(V, 0);
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                firstDfs(i, adj, vis, st);
            }
        }
        
        int node=st.top();
        
        vis=vector<bool>(V, 0);
        
        dfs(node, adj, vis);
        
        for(int i=0; i<V; i++){
            if(!vis[i]) return -1;
        }
        
        return node;
    }
};