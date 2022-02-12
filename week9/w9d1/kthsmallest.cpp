struct Node {
  int data;
  Node* left, *right;
  int lcount; //Number of nodes on the lesft of the node
}

Node* kthSmallest(Node* root, int k)
{
    // base case
    if (root == NULL)
        return NULL;
 
    int count = root->lCount + 1;
    if (count == k)
        return root;
 
    if (count > k)
        return kthSmallest(root->left, k);
 
    // else search in right subtree
    return kthSmallest(root->right, k - count);
}
