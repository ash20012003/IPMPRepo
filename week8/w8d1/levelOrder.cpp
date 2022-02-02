void printLevelOrder(node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}
 
/* Print nodes at a current level */
void printCurrentLevel(node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

/*   OR   */

class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
      //Your code here
      vector<int> ans;
      queue<int> q;
      Node *t;
      q.push(node);
      while(!q.empty()){
          t=q.pop();
          ans.push_back(t->data);
          if(t->left) {ans.push_back((t->left)->data); q.push(t->left);}
          if(t->right) {ans.push_back((t->right)->data); q.push(t->right);}
          
      }
      return ans;
    }
};
