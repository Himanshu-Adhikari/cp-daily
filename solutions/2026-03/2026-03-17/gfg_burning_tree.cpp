
class Solution {
  public:
        map<int,vector<int>>m;
    void rec(Node*r){
        if(r->left){
            m[r->left->data].push_back(r->data);
            m[r->data].push_back(r->left->data);
            rec(r->left);
        }
        if(r->right){
            m[r->right->data].push_back(r->data);
            m[r->data].push_back(r->right->data);
            rec(r->right);
        }
    }
    int minTime(Node* root, int target) {
        rec(root);
        queue<int>q;
        map<int,int>vis;
        int res=0;
        q.push(target);
        while(!q.empty()){
            int s=q.size();
            while(s--){
                int c=q.front();q.pop();
                vis[c]=1;
                for(auto d:m[c]){
                    if(!vis[d])q.push(d);
                }
            }
            if(q.size())res++;
        }
        return res;
    }
};