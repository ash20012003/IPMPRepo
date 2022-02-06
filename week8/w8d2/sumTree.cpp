class Solution
{
    public:
    int sumChild(Node* root){
        if(root==NULL) return 0;
        int l =  sumChild(root->left);
        int r =  sumChild(root->right);
        return l+r+root->data;
    }
    
    bool isSumTree(Node* root)
    {
         // Your code here
         int sum = sumChild(root) - root->data;
         if(sum==0) return true;
         if(sum == root->data)
            return true;
        return false;
    }
};
