class Solution{
  public:
    // Return True if the given trees are isomotphic. Else return False.
    bool isIsomorphic(Node *n1,Node *n2)
    {
    //add code here.
    if (n1 == NULL && n2 == NULL)
    return true;
 
 if (n1 == NULL || n2 == NULL)
    return false;
 
 if (n1->data != n2->data)
    return false;
 
 return
 (isIsomorphic(n1->left,n2->left) && isIsomorphic(n1->right,n2->right))||
 (isIsomorphic(n1->left,n2->right) && isIsomorphic(n1->right,n2->left));
    }
};
