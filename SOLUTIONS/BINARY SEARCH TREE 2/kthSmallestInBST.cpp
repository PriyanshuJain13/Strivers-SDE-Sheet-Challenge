class Solution {
    void solve(vector<int>& arr,TreeNode* root)
    {
        if(root == NULL) return ;
        arr.push_back(root->val);
        solve(arr,root->left);
        solve(arr,root->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr;
        solve(arr,root);
        sort(arr.begin(),arr.end());
        return arr[k-1];
    }
};
