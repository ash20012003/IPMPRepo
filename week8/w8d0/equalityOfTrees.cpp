class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        //Your Code here
        if(r1==NULL && r2==NULL) return true;
        if(r1->data == r2->data){
            bool left = isIdentical(r1->left,r2->left);
            bool right = isIdentical(r1->right,r2->right);
            if(left==true && right==true) return true;
            else return false;
        }
        else return false;
    }
};
