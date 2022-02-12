class Solution{
  public:
  struct Node* minValue(struct Node* node)
{
    Node* current = node;
 
    // Loop down to find the leftmost leaf
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *n)
    {
        //Your code here
         if (n->right != NULL)
        return minValue(n->right);
 
    struct Node* succ = NULL;
 
    // Start from root and search for
    // successor down the tree
    while (root != NULL)
    {
        if (n->data < root->data)
        {
            succ = root;
            root = root->left;
        }
        else if (n->data > root->data)
            root = root->right;
        else
            break;
    }
 
    return succ;
        
    }
};
