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
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }
        int ans = 1;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});

        while(!q.empty())
        {
            int n = q.size();
            int start = q.front().second;
            int end = q.back().second;

            ans = max(ans,end-start+1);

            for(int i = 0;i < n;i++)
            {
                auto it = q.front();
                TreeNode* node = it.first;
                int val = it.second;
                q.pop();

                if(node->left)
                {
                    q.push({node->left,2LL*val+1});
                }
                if(node ->right)
                {
                    q.push({node->right,2LL*val+2});
                }
                
            }
        }

        return ans;
        
    }
};
