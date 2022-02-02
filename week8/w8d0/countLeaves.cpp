int height(Node* p){
    int x,y;
  if(p==NULL) return 0;
  x=height(p->left);
  y=height(p->right);
  if(x>y) return x+1;
  else return y+1;
}

int countLeaves(Node* root)
{
  // Your code here
  if(root==NULL) return 0;
  if(height(root)==1) return 1;
  return countLeaves(root->left) + countLeaves(root->right);
}
