class Solution {
public:
    vector<int> printLeaves(Node* root)
    {
        static std::vector<int> ans;
        if (root == NULL)
            {
                vector<int> w;
                return w;
            }
 
        printLeaves(root->left);
 
        // Print it if it is a leaf node
        if (!(root->left) && !(root->right))
            ans.push_back(root->data);
 
        printLeaves(root->right);
        return ans;
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> left;
        vector<int> right;
        vector<int> ans;
        if(root==NULL) return ans;
        ans.push_back(root->data);
        Node* l = root;
        Node* r = root;
        while(l!=NULL){
            left.push_back(l->data);
            l=l->left;
        }
        while(r!=NULL){
            right.push_back(r->data);
            r=r->right;
        }
        vector<int> leaf;
        leaf=printLeaves(root);
        for(int i=1;i<left.size()-1;i++) ans.push_back(left[i]);
        for(int i=0;i<leaf.size();i++) ans.push_back(leaf[i]);
        for(int i=right.size()-2;i>0;i--) ans.push_back(right[i]);
        return ans;
    }
};

/* OR */

void printLeaves(struct node* root)
{
    if (root == NULL)
        return;
 
    printLeaves(root->left);
 
    // Print it if it is a leaf node
    if (!(root->left) && !(root->right))
        printf("%d ", root->data);
 
    printLeaves(root->right);
}
 
// A function to print all left boundary nodes, except a leaf node.
// Print the nodes in TOP DOWN manner
void printBoundaryLeft(struct node* root)
{
    if (root == NULL)
        return;
 
    if (root->left) {
 
        // to ensure top down order, print the node
        // before calling itself for left subtree
        printf("%d ", root->data);
        printBoundaryLeft(root->left);
    }
    else if (root->right) {
        printf("%d ", root->data);
        printBoundaryLeft(root->right);
    }
    // do nothing if it is a leaf node, this way we avoid
    // duplicates in output
}
 
// A function to print all right boundary nodes, except a leaf node
// Print the nodes in BOTTOM UP manner
void printBoundaryRight(struct node* root)
{
    if (root == NULL)
        return;
 
    if (root->right) {
        // to ensure bottom up order, first call for right
        // subtree, then print this node
        printBoundaryRight(root->right);
        printf("%d ", root->data);
    }
    else if (root->left) {
        printBoundaryRight(root->left);
        printf("%d ", root->data);
    }
    // do nothing if it is a leaf node, this way we avoid
    // duplicates in output
}
 
// A function to do boundary traversal of a given binary tree
void printBoundary(struct node* root)
{
    if (root == NULL)
        return;
 
    printf("%d ", root->data);
 
    // Print the left boundary in top-down manner.
    printBoundaryLeft(root->left);
 
    // Print all leaf nodes
    printLeaves(root->left);
    printLeaves(root->right);
 
    // Print the right boundary in bottom-up manner
    printBoundaryRight(root->right);
}
