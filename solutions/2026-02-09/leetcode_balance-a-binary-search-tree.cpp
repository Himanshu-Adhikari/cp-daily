class Solution {
public:
    vector<TreeNode*> v;
    int n;
    void rec(TreeNode* root) {
        if (!root)
            return;
        rec(root->left);
        v.push_back(root);
        rec(root->right);
    }
    TreeNode* bld(int l, int r) {
        if (l >r)
            return NULL;
        int m=l+(r-l)/2; 
        TreeNode* res = v[m];
        res->left = bld(l, m-1);
        res->right = bld(m + 1, r);
        return res;
    }
    TreeNode* balanceBST(TreeNode* root) {
        rec(root);
        n = v.size();
        return bld(0, n - 1);
    }
};