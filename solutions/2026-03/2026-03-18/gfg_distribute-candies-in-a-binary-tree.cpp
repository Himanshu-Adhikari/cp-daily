
class Solution {
  public:
    int res=0;
    int rec(Node *root){
        if(!root)return 0;
        int l=rec(root->left);
        int r=rec(root->right);
        res+=abs(l)+abs(r);
        return root->data+l+r-1;
    }
    int distCandy(Node* root) {
        rec(root);
        return res;
    }
};