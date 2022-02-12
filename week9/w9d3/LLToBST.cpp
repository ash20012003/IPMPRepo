class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int right = 0;
        ListNode* tmp = head;
        
        while(tmp) {
            tmp = tmp->next;
            ++right;
        }
        
        return build(0, right - 1, head);
    }
    
    private:
    TreeNode* build(int L, int R, ListNode* &head) {
        if (L > R) return nullptr;
        
        int mid = L + (R - L) / 2;
        
        TreeNode* left = build(L, mid - 1, head);
        
		//head in LL is root in In-order traverse, after finishing left side
        TreeNode* root = new TreeNode (head->val);
        head = head->next;  //move to next node in LL
        
		//connect tree
		root->left = left;
        root->right = build(mid + 1, R, head);
        
        return root;
    }
};
