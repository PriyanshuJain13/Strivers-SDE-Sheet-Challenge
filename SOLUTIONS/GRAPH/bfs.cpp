class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        vector<int> ans;
        
        queue<int> q;
        vis[0] = 1;
        q.push(0);
        while(!q.empty())
        {
            int it = q.front();
            q.pop();
            ans.push_back(it);
            for(auto i: adj[it])
            {
                if(!vis[i])
                {
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }
        
        return ans;
        
    }
};
