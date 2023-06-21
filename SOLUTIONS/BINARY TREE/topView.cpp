class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if(root == NULL)
        {
            return ans;
        }
        
        map<int,int> m;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            Node* curr = it.first;
            int line = it.second;
            if(m.find(line) == m.end()) m[line] = curr->data;
            
            if(curr->left != NULL)
            {
                q.push({curr->left,line-1});
            }
            if(curr->right != NULL)
            {
                q.push({curr->right,line+1});
            }
        }
        
        for(auto it : m)
        {
            ans.push_back(it.second);
        }
        
        return ans;
    }

};
