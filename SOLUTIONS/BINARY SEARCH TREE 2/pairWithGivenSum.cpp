class Solution {
public:
    
    void traversal(TreeNode* root,vector<int>& vec)
    {
        if(root==NULL)
        {
            return;
        }
        traversal(root->left,vec);
        vec.push_back(root->val);
        traversal(root->right,vec);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> vec;
        traversal(root,vec);
        map<int,int> mp;
        for(int i = 0;i < vec.size();i++)
        {
            mp.insert({i,vec[i]});

        }
        for(int i = 0;i < vec.size();i++)
        {
            int x= vec[i];
            int target =k-x;
            for(int j=0;j <vec.size();j++)
            {
                if(vec[j]==target && i!=j)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
