class Solution {
  public:
        #define ll long long
        map<ll,ll>m;
    ll rec(ll sm,int k,Node*rt){
        if(!rt)return 0;
        sm+=rt->data;
        ll res=m[sm-k];
        m[sm]++;
        res+=rec(sm,k,rt->left);
        res+=rec(sm,k,rt->right);
        m[sm]--;
        return res;
    }
    int countAllPaths(Node *root, int k) {
        m[0]=1;
        return rec(0,k,root);
    }
};