
Node* modifyBSTUtil(Node* root, int* sum)
{
    // Base Case
    if (root == NULL)
        return NULL;
 
    // Recur for right subtree
    modifyBSTUtil(root->right, sum);
 
    // Now *sum has sum of nodes
    // in right subtree, add
    // root->data to sum and
    // update root->data
    *sum = *sum + root->data;
    root->data = *sum;
 
    // Recur for left subtree
    modifyBSTUtil(root->left, sum);
    
    return root;
}

Node* modify(Node *root)
{
    // Your code here
    int sum = 0;
    modifyBSTUtil(root, &sum);
}
