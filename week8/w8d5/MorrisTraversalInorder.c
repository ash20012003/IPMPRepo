vector<int> inorder(struct node* root){
  struct node* cur  = root;
  vector<int> inorder;
  while(cur!=NULL){
    if(cur->left==NULL){
      inorder.push_back(cur->data);
      cur = cur->right;
    }
    else{
      struct node* prev = cur->left;
      while(prev->right != NULL && prev->right != cur){
        prev = prev->right;
      }
      if(prev->right==NULL) {
        prev->right = cur;
        cur = cur->left;
      }
      else{
        prev->right = NULL;
        inorder.push_back(cur->data);
        cur = cur->right;
      }
    }
  }
  return inorder;
}
