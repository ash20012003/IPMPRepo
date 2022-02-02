void deleteTree(node* node)
{
    if (node == NULL) return;
 
    /* first delete both subtrees */
    deleteTree(node->left);
    deleteTree(node->right);
     
    /* then delete the node */
    cout << "\n Deleting node: " << node->data;
    delete node;
}
