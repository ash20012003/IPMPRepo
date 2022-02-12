int minValue(Node* root) {
    // Code here
    Node *current = root;
    if(root == NULL) return -1;
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
    {
        current = current->left;
    }
    return(current->data);
}
