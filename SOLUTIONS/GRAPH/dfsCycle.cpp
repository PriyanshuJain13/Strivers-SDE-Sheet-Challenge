class Solution {
    bool check(vector<int>& vis,vector<int> adj[],int node,vector<int> &vis2)
    {
        vis[node] = 1;
        vis2[node] = 1;
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                if(check(vis,adj,it,vis2))
                {
                    return true;
                }
            }else if(vis[it] && vis2[it])
            {
                return true;
            }
        }
        vis2[node] = 0;

        return false;

    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses,0);
        vector<int> vis2(numCourses,0);
        vector<int> adj[numCourses];
        for(auto it : prerequisites)
        {
            vector<int> edge = it;
            adj[edge[0]].push_back(edge[1]);
        }
        for(int i = 0;i < numCourses;i++)
        {
            if(!vis[i])
            {
                if(check(vis,adj,i,vis2)){
                    return false;
                }
            }
        }

        return true;
    }
};
