
class Solution {
    TreeNode* solve(vector<int>& in,vector<int>& po,int start,int end,int& temp)
    {
        if(start > end)
        {
            return NULL;
        }
        TreeNode* cur = new TreeNode(po[temp]);
        temp++;
        int i;
        for(i = start;i <= end;i++)
        {
            if(cur->val == in[i])
            {
                break;
            }
        }

        cur->right = solve(in,po,i+1,end,temp);
        cur->left = solve(in,po,start,i-1,temp);

        return cur;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        reverse(postorder.begin(),postorder.end());
        int temp = 0;
        return solve(inorder,postorder,0,inorder.size()-1,temp);
    }
};
