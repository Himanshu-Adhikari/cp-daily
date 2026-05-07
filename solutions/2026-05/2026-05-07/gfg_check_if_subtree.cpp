class Solution {
  public:
    bool rec(Node*r,Node*s){
        if(!r and !s)return true;
        if(!r or !s or s->data != r->data)return false;
        return rec(r->right,s->right) && rec(r->left,s->left);
    }
    bool isSubTree(Node *root1, Node *root2) {
        if(!root1)return false;
        if(root1->data==root2->data and rec(root1,root2))return true;
        return isSubTree(root1->left,root2) || isSubTree(root1->right,root2);
    }
};