class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        map<int,vector<pair<int,int>>>m;
        for(auto c:edges){
            m[c[0]].push_back({c[1],c[2]});
            m[c[1]].push_back({c[0],2*c[2]});
        }
        #define ll long long
        vector<ll>dist(n,INT_MAX);
        priority_queue<pair<int,int>>pq;
        pq.push({0,0});
        dist[0]=0;
        while(!pq.empty()){
            auto [val,u]=pq.top();pq.pop();
            val=-val;
            if(dist[u]<val)continue;
            for(auto [v,uv]:m[u]){
                if(dist[v]>val+uv){
                    dist[v]=val+uv;
                    pq.push({-dist[v],v});
                }
            }
        }
        return dist[n-1]==INT_MAX?-1:dist[n-1];
    }
};