int ancestorMatrixRec(Node *root, vector<int> &anc)
{
    /* base case */
    if (root == NULL) return 0;;
 
    // Update all ancestors of current node
    int data = root->data;
    for (int i=0; i<anc.size(); i++)
       mat[anc[i]][data] = true;
 
    // Push data to list of ancestors
    anc.push_back(data);
 
    // Traverse left and right subtrees
    int l = ancestorMatrixRec(root->left, anc);
    int r = ancestorMatrixRec(root->right, anc);
 
    // Remove data from list the list of ancestors
    // as all descendants of it are processed now.
    anc.pop_back();
 
    return l+r+1;
}
