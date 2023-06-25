class Solution {
public:

    class struc
    {
        public: 
        int maxi;
        int mini;
        bool isBST;
        int sum;
    };

    struc solve(TreeNode* root, int &ans)
    {
        if(root==NULL)
        {
            return {INT_MIN, INT_MAX, true, 0};
        }

        struc left=solve(root->left, ans);
        struc right=solve(root->right, ans);

        struc currNode;

        currNode.sum=left.sum + right.sum + root->val;
        currNode.maxi=max(root->val, right.maxi);
        currNode.mini=min(root->val, left.mini);

        if(left.isBST && right.isBST && (root->val > left.maxi && root->val < right.mini))
        {
            currNode.isBST=true;
        }else
        {
            currNode.isBST=false;
        }

        if(currNode.isBST)
        {
            ans=max(ans, currNode.sum);
        }

        return currNode;
    }

    int maxSumBST(TreeNode* root) {
        
        int maxSum=0;
        struc temp=solve(root, maxSum);
        return maxSum;
    }
};
