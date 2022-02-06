class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* root) {
        // code here
        if(root == NULL) return;
        Node* a;
        a = root->left;
        root->left = root->right;
        root->right = a;
        mirror(root->left);
        mirror(root->right);
    }
};
