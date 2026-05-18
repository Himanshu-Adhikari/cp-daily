class Solution {
public:
    int minJumps(vector<int>& arr) {
        
        map<int,multiset<int>>m;
        int n=arr.size();
        for(int i=0;i<n;i++){
            m[arr[i]].insert(i);
        }
        queue<int>q;
        q.push(0);
        m[arr[0]]. erase(0);
        vector<int>v(n,0);
        int res=0,s=0;
        while(!q.empty()){
            s=q.size();
            while(s--){
                int c=q.front();
                q.pop();
                if(c==n-1)return res;
                if(c<n-1 and !v[c+1]){
                    m[arr[c+1]].erase(c+1);
                    q.push(c+1);v[c+1]=1;
                }
                if(c and !v[c-1]){
                    v[c-1]=1;
                    m[arr[c-1]].erase(c-1);
                    
                    q.push(c-1);
                }
                for(auto id:m[arr[c]]){
                    if(!v[id]){
                        v[id]=1;
                        m[arr[id]].erase(id);
                        q.push(id);
                    }
                }
            }res++;
        }
        return n;
    }
};