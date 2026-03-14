class Solution {
  public:
    map<int,int>m;
    map<int,int>md;
    void rec(int i,int d,Node*r){
        if(!r)return;
        if(!m.count(i))m[i]=r->data,md[i]=d;
        else {
            if(md[i]>d){
                md[i]=d;
                m[i]=r->data;
            }
        }
        rec(i-1,d+1,r->left);
        rec(i+1,d+1,r->right);
    }
    vector<int> topView(Node *root) {
        vector<int>res;
        rec(0,0,root);
        for(auto [a,b]:m)res.push_back(b);
        return res;
    }
};

   