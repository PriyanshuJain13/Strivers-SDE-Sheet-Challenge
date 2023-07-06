class Solution {
public:
    bool solve(int s,int x,vector<int> &vis,vector<vector<int>> &adj){
        if(vis[s]!=-1)
        {
            if(vis[s] != x)return false;
            return true;
        }
        vis[s] = x;
        bool ans = true;
        for(auto &i: adj[s]){
            ans &= solve(i,x^1,vis,adj);
        }
        return ans;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(),i;
        vector<int> vis(n,-1);
        vector<vector<int>> adj(n);

        for(i = 0; i < n; i++)
        {
            for(auto &j: graph[i]){
                adj[i].push_back(j);
            }
        }
        bool ans = true;
        for(i = 0; i < n; i++)
        {
            if(vis[i] == -1)
            {
                ans &= solve(i,0,vis,adj);
            }
        }
        return ans;
    }
};
