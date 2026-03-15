
class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        map<int,vector<int>>m;
        vector<vector<int>>res;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        int d=0;
        while(!q.empty()){
            int s=q.size();
            while(s--){
                auto [r,d]=q.front();q.pop();
                m[d].push_back(r->data);
                if(r->left)q.push({r->left,d-1});
                if(r->right)q.push({r->right,d+1});
            }
        }
        for(auto[_,a]:m)res.push_back(a);
        return res;
    }
};