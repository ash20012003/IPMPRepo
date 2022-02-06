class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    int height(Node *root){
        if(root == NULL) return 0;
        int l = height(root->left);
        int r = height(root->right);
        if(l>r) return l+1;
        else return r+1;
    }
    bool isBalanced(Node *root)
    {
        //  Your Code here
        if(root == NULL) return true;
        if(abs(height(root->left) - height(root->right)) == 0 || abs(height(root->left) - height(root->right)) == 1)
            return isBalanced(root->left) && isBalanced(root->right);
        return false;
        
    }
};
