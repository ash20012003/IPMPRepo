vector<int> preorder(struct node* root){
  struct node* cur  = root;
  vector<int> preorder;
  while(cur!=NULL){
    if(cur->left==NULL){
      preorder.push_back(cur->data);
      cur = cur->right;
    }
    else{
      struct node* prev = cur->left;
      while(prev->right != NULL && prev->right != cur){
        prev = prev->right;
      }
      if(prev->right==NULL) {
        prev->right = cur;
        preorder.push_back(cur->data);
        cur = cur->left;
      }
      else{
        prev->right = NULL;
        cur = cur->right;
      }
    }
  }
  return preorder;
}
