class Solution
{
    void solve(vector<int>& arr,Node* root)
    {
        if(root == NULL) return ;
        arr.push_back(root->data);
        solve(arr,root->left);
        solve(arr,root->right);
    }
    public:
    int kthLargest(Node *root, int K)
    {
        vector<int> arr;
        solve(arr,root);
        sort(arr.begin(),arr.end());
        int n = arr.size();
        return arr[n-K];
    }
};
