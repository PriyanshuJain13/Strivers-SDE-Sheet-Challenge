class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL)
        {
            return ans;
        }

        queue<pair<TreeNode*,pair<int,int>>> q;
        int v = 0;
        int level = 0;
        map<int,map<int,multiset<int>>> m;
        q.push({root,{level,v}});
        while(!q.empty())
        {
            int n = q.size();

            for(int i = 0;i < n;i++)
            {
                auto temp = q.front();
                q.pop();
                auto node = temp.first;
                m[temp.second.second][temp.second.first].insert(node->val);
                if(node->left)
                {
                    q.push({node->left,{temp.second.first+1,temp.second.second-1}});
                }
                if(node->right)
                {
                    q.push({node->right,{temp.second.first+1,temp.second.second+1}});
                }
            }
        }

        for(auto it:m)
        {
            vector<int> temp;
            for(auto jt:it.second){
                for(auto kt:jt.second){
                    temp.push_back(kt);
                }
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
