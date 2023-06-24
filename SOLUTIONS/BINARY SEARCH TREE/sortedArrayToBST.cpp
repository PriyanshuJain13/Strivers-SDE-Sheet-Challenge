class Solution {
    TreeNode* solve(vector<int>& nums,int l,int r)
    {
        if(l > r)
        {
            return NULL;
        }
        int m = l + (r-l)/2;
        TreeNode* root = new TreeNode(nums[m]);
        root->left = solve(nums,l,m-1);
        root->right = solve(nums,m + 1,r);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums,0,nums.size()-1);
    }
};
