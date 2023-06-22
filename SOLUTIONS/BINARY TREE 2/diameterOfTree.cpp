class Solution {
    int ans = 0;

public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxHeight(root);
        return ans;
    }

    int maxHeight(TreeNode* root) {
        if (root == NULL) return 0;

        int x = maxHeight(root->left);
        int y = maxHeight(root->right);

        ans = max(ans, x+y);

        return max(x,y) + 1;
    }
};
