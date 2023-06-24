class Solution {
    TreeNode* solve(vector<int>& preorder,int mini,int maxi,int& ind)
    {
        int n = preorder.size();
        if(ind >= n) return NULL;
        if(preorder[ind] < mini || preorder[ind] > maxi)
        {
            return NULL;
        }

        TreeNode* node = new TreeNode(preorder[ind]);
        ind++;
        node->left = solve(preorder,mini,node->val,ind);
        node->right = solve(preorder,node->val,maxi,ind);
        return node;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ind = 0;
        return solve(preorder,INT_MIN,INT_MAX,ind);
    }
};
