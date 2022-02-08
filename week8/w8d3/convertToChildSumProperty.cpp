void increment(node* node, int diff);
 
/* This function changes a tree
to hold children sum property */
void convertTree(node* node)
{
    int left_data = 0, right_data = 0, diff;
     
    /* If tree is empty or it's a leaf 
        node then return true */
    if (node == NULL || (node->left == NULL &&
                        node->right == NULL))
        return;
    else
    {
        /* convert left and right subtrees */
        convertTree(node->left);
        convertTree(node->right);
     
        /* If left child is not present then 0 is used
        as data of left child */
        if (node->left != NULL)
        left_data = node->left->data;
     
        /* If right child is not present then 0 is used
        as data of right child */
        if (node->right != NULL)
        right_data = node->right->data;
     
        /* get the diff of node's data and children sum */
        diff = left_data + right_data - node->data;
     
        /* If node's children sum is
        greater than the node's data */
        if (diff > 0)
        node->data = node->data + diff;
     
        /* THIS IS TRICKY --> If node's data
        is greater than children sum,
        then increment subtree by diff */
        if (diff < 0)
        increment(node, -diff); // -diff is used to make diff positive
    }
}
 
/* This function is used
to increment subtree by diff */
void increment(node* node, int diff)
{
    /* IF left child is not
    NULL then increment it */
    if(node->left != NULL)
    {
        node->left->data = node->left->data + diff;
     
        // Recursively call to fix
        // the descendants of node->left
        increment(node->left, diff);
    }
    else if (node->right != NULL) // Else increment right child
    {
        node->right->data = node->right->data + diff;
     
        // Recursively call to fix
        // the descendants of node->right
        increment(node->right, diff);
    }
}
