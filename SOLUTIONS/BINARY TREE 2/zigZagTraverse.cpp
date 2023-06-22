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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL)
	{
		return ans;
	}
        int flag = 0;
        queue<TreeNode*> s;
        s.push(root);
        while (!s.empty())
	{
		int size = s.size();

		vector<int> temp;
		for (int i = 0; i < size; i++)
		{
			TreeNode *curr = s.front();
			temp.push_back(curr->val);
			s.pop();
			if (curr->left)
			{
				s.push(curr->left);
			}
			if (curr->right)
			{
				s.push(curr->right);
			}
		}
		int n = temp.size();
		if (flag == 0)
		{
			ans.push_back(temp);
		}
		else
		{
			reverse(temp.begin(),temp.end());
			ans.push_back(temp);
		}
		flag = !flag;
	}

	return ans;
        
    }
};
