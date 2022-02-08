class Solution
{
    
    public:
   
    bool hasPathSum(Node *root, int sum) {
    // Your code here
     bool ans = 0;
 
  int subSum = sum - root->data;
 
  /* If we reach a leaf node and sum becomes 0 then return true*/
  if ( subSum == 0 && root->left == NULL && root->right == NULL )
    return 1;
 
  /* otherwise check both subtrees */
  if(root->left)
    ans = ans || hasPathSum(root->left, subSum);
  if(root->right)
    ans = ans || hasPathSum(root->right, subSum);
 
  return ans;
    
}
};
