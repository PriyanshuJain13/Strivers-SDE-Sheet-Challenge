class Solution {
    void solve(TreeNode* root,TreeNode* &prev,stack<TreeNode*>& st)
    {
        while(!st.empty())
        {
            TreeNode* temp = st.top();
            st.pop();
            if(temp->right) st.push(temp->right);
            if(temp->left) st.push(temp->left);
            if(!st.empty())
            {
                temp->right = st.top();
            }
            temp->left = NULL;
        }
    }
public:
    void flatten(TreeNode* root) {
        if(root == NULL)
        {
            return;
        }

        TreeNode* prev = NULL;
        stack<TreeNode*> st;
        st.push(root);
        return solve(root,prev,st);

    }
};
