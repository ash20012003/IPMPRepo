node* buildTree (int inorder[], int start, int end)
{
    if (start > end)
        return NULL;
 
    /* Find index of the maximum element from Binary Tree */
    int i = max (inorder, start, end);
 
    /* Pick the maximum value and make it root */
    node *root = newNode(inorder[i]);
 
    /* If this is the only element in inorder[start..end],
    then return it */
    if (start == end)
        return root;
 
    /* Using index in Inorder traversal, construct left and
    right subtress */
    root->left = buildTree (inorder, start, i - 1);
    root->right = buildTree (inorder, i + 1, end);
 
    return root;
}
 
/* UTILITY FUNCTIONS */
/* Function to find index of the maximum value in arr[start...end] */
int max (int arr[], int strt, int end)
{
    int i, max = arr[strt], maxind = strt;
    for(i = strt + 1; i <= end; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
            maxind = i;
        }
    }
    return maxind;
}
