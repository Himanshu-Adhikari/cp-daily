
class Solution {
  public:
    vector<Node*>res={NULL,NULL};
    void rec(Node* root, int key){
        if(!root)return;
        rec(root->left,key);
        if(root->data<key)res[0]=root;
        if(root->data>key and res[1]==NULL)res[1]=root;
        rec(root->right,key);
    }
    vector<Node*> findPreSuc(Node* root, int key) {
        rec(root,key);
        return res;
    }
};