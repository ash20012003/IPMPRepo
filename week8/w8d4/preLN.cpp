struct Node *constructTreeUtil(int pre[], char preLN[], int *index_ptr, int n)
{
    int index = *index_ptr; // store the current value of index in pre[]
 
    // Base Case: All nodes are constructed
    if (index == n)
        return NULL;
 
    // Allocate memory for this node and increment index for
    // subsequent recursive calls
    Node *temp = new Node( pre[index] );
    (*index_ptr)++;
 
    // If this is an internal node, construct left and right subtrees and link the subtrees
    if (preLN[index] == 'N')
    {
      temp->left  = constructTreeUtil(pre, preLN, index_ptr, n);
      temp->right = constructTreeUtil(pre, preLN, index_ptr, n);
    }
 
    return temp;
}
struct Node *constructTree(int n, int pre[], char preLN[])
{
    // Code here
    int index = 0;
    return constructTreeUtil(pre,preLN,&index,n);
}
