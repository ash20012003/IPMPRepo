class Solution {
  public:
    vector<int> ans;
    
    vector<int> printNearNodes(Node *root, int low, int high) {
        //code here
        //if(root == NULL) return;
        if(root->data < low) printNearNodes(root->right,low,high);
        else if(root->data > high) printNearNodes(root->left,low,high);
        else if(root->data == low){
            ans.push_back(root->data);
            //printNearNodes(root->left,low,high);
            printNearNodes(root->right,low,high);
        }
        else if(root->data == high){
            ans.push_back(root->data);
            printNearNodes(root->left,low,high);
        }
        else{
            ans.push_back(root->data);
            if(root->left || root->right){
            printNearNodes(root->left,low,high);
            printNearNodes(root->right,low,high);
            }
            return ans;
        }
        return ans;
    }
};
