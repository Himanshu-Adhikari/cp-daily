class Solution {
public:
   
    bool valid(int i, int j){
        return i<n && j<m ; 
    }
    int m ,n ; 
    int minCost(vector<vector<int>>& grid, int k) {
        vector<int>visitedforeachk(k+1,0) ; 
         n = grid.size() ; 
         m = grid[0].size() ; 
        vector<tuple<int,int,int>>vec ; 
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ;j++){
                vec.push_back({grid[i][j] , i ,j}) ; 
            }
        }
        sort(vec.begin() , vec.end()) ;

        priority_queue<tuple<int,int,int,int> , vector<tuple<int,int,int,int>> ,greater<tuple<int,int,int,int>>> pq ; 
        pq.push({0,0,0,0}) ; 
        vector<vector<vector<int>>>dist (n,vector<vector<int>>(m,vector<int>(k+1, INT_MAX)))  ; 
        
        while(!pq.empty()){
            auto[cost , currk ,i ,j ] = pq.top() ; 
            pq.pop() ; 
            if(i==n-1 && j==m-1)return cost;
            int newcost ; 
            if(valid(i+1,j)){
                newcost = cost+grid[i+1][j] ; 
                if(newcost<dist[i+1][j][currk]){
                    pq.push({newcost ,currk ,i+1,j}) ; 
                    dist[i+1][j][currk]=newcost ; 
                }
            }
            if(valid(i,j+1)){
                newcost = cost+grid[i][j+1] ; 
                if(newcost<dist[i][j+1][currk]){
                    pq.push({newcost ,currk ,i,j+1}) ; 
                    dist[i][j+1][currk]=newcost ; 
                }
            }
            if(currk<k){
                int r = visitedforeachk[currk];
                for(; r<vec.size() ; r++){
                    auto[c ,ni ,nj] = vec[r] ; 
                    if(c>grid[i][j])break ; 
                    if(cost<dist[ni][nj][currk+1]){
                        pq.push({cost, currk+1 , ni,nj}) ; 
                        dist[ni][nj][currk+1] = cost ; 
                    }
                }
                visitedforeachk[currk] = r; 
            }

        }
       
        return -1 ;
    }
};