class BSTIterator {
    stack<TreeNode *> st;
public:
    BSTIterator(TreeNode *root) {
        pushAll(root);
    }

    bool hasNext() {
        return !st.empty();
    }

    int next() {
        TreeNode *temp = st.top();
        st.pop();
        pushAll(temp->right);
        return temp->val;
    }

private:
    void pushAll(TreeNode *node) {
        while(node != NULL)
        {
            st.push(node);
            node = node->left;
        }
    }
};
