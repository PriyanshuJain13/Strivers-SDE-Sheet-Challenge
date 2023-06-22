/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool ans = true;
    int maxHeight(TreeNode* root) {
        if (root == NULL) return 0;

        int x = maxHeight(root->left);
        int y = maxHeight(root->right);

        if(abs(x-y) > 1)
        {
            ans = false;
        }

        return max(x,y) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
        {
            return true;
        }
        maxHeight(root);

        return ans;
    }
};
