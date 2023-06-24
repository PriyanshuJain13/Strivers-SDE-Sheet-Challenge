class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL)
        {
            return NULL;
        }
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            
            for(int i = 0;i < n;i++)
            {
                auto it = q.front();
                q.pop();
                if(i < n-1)
                {
                    it->next = q.front();
                }
                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
            }
        }

        return root;
    }
};
