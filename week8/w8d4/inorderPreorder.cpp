/* MY SOLLUTION */
 Node* buildTree(int in[],int pre[], int n)
    {
        //Code here
        Node* root = new Node;
        root->data = pre[n-1];
        root->left = root->right = NULL;
        Node *t = root;
        int  i = 0;
        for(i=0;i<n;i++){
            if(in[i]==pre[n-1])
                break;
        }
        int *in1 = new int(i);
        int *in2 = new int(n-i-1);
        int *pre1 = new int(i);
        int *pre2 = new int(n-i-1);
        for(int j = 0;j<i;j++) in1[j] = in[j];
        for(int j = i+1;j<n;j++) in2[j] = in[j];
        for(int j = 0;j<n;j++) {
            if(pre[j]!=root->data && binarySearch(in1,0,i-1,pre[j]))
            pre1[j] = pre[j];
        }
        for(int j = 0;j<n;j++) {
            if(pre[j]!=root->data && binarySearch(in2,0,n-i-2,pre[j]))
            pre2[j] = pre[j];
        }
        root->left = buildTree(in1,pre1,i);
        root->right = buildTree(in2,pre2,n-i-1);
        return root;
    }

/* OR */
class Solution{
    public:
    set<Node*> s;
    stack<Node*> st;
    
    Node* buildTree(int inorder[],int preorder[], int n)
    {
        Node* root = NULL;
    for (int pre = 0, in = 0; pre < n;)
    {
 
        Node* node = NULL;
        do
        {
            node = new Node(preorder[pre]);
            if (root == NULL)
            {
                root = node;
            }
            if (st.size() > 0)
            {
                if (s.find(st.top()) != s.end())
                {
                    s.erase(st.top());
                    st.top()->right = node;
                    st.pop();
                }
                else
                {
                    st.top()->left = node;
                }
            }
            st.push(node);
        } while (preorder[pre++] != inorder[in] && pre < n);
 
        node = NULL;
        while (st.size() > 0 && in < n &&
                st.top()->data == inorder[in])
        {
            node = st.top();
            st.pop();
            in++;
        }
 
        if (node != NULL)
        {
            s.insert(node);
            st.push(node);
        }
    }
 
    return root;
    }
};
