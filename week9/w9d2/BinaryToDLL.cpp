class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    void in(Node* root,vector<Node*> &l){ //Get the inorder of the binary tree
        if(!root)return;
        in(root->left,l);
        l.push_back(root);
        in(root->right,l);
    }
    Node * bToDLL(Node *root)
    {
        if(!root)return NULL;
        vector<Node*> l;
        in(root,l);
        Node *head = l[0];
        head->left = NULL;
        Node *t = head;
        for(int i=1;i<l.size();i++){
            t->right = l[i];
            l[i]->right = NULL;
            l[i]->left = t;
            t = l[i];
        }
        return head;
    }
};
