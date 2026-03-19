/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a 
    vector<int> solve(Node* root){
        if(root==NULL){
            return {0, 1, INT_MAX, INT_MIN};
        }
        
        if(root->left==NULL && root->right==NULL){
            return {1, 1, root->data, root->data};
        }
        
        vector<int>lft=solve(root->left);
        vector<int>rgt=solve(root->right);
        
        int lftCnt=lft[0], lftAns=lft[1], lftMax=lft[3], lftMin=lft[2];
        int rgtCnt=rgt[0], rgtAns=rgt[1], rgtMax=rgt[3], rgtMin=rgt[2];
        
        if(lftAns==1 && rgtAns==1 && root->data>lftMax && root->data<rgtMin){
            return {lftCnt+rgtCnt+1, 1, min(root->data, lftMin), max(root->data, rgtMax)};
        }else{
            return {max(lftCnt, rgtCnt), 0, 0, 0};
        }
        
    }
    
    int largestBst(Node *root)
    {
    	//Your code here
    	return solve(root)[0];
    }
};