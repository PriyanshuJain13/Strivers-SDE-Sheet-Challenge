class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        if(root == NULL)
        {
            return ans;
        }
        
        queue<pair<Node*,int>> q;
        q.push({root,0});
        map<int,int> m;
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            Node* curr = it.first;
            int line = it.second;
            
            m[line] = curr->data;
            
            if(curr->left)
            {
                q.push({curr->left,line-1});
            }
            if(curr->right)
            {
                q.push({curr->right,line+1});
            }
    
        }
        
        for(auto it: m)
        {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};
