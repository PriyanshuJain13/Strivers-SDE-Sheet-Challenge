class Solution {
public:
    bool f(TreeNode*r1,TreeNode*r2){
        if(!r1||!r2)
            return r1==r2;
        if(r1->val==r2->val){
            return f(r1->left,r2->right)&&f(r1->right,r2->left);
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return f(root->left,root->right);
    }
};
