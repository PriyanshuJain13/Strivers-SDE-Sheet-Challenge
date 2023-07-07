class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0}); 
        vector<int> vis(V,0);
        int ans=0;
        while(!pq.empty()){
            int node=pq.top().second;
            int wt=pq.top().first;
            pq.pop();
            
            if(vis[node]==0){
                vis[node]=1;
                ans+=wt;
                
                for(auto it:adj[node]){
                    int new_node=it[0];
                    int new_wt=it[1];
                    if(vis[new_node]==0){
                        pq.push({new_wt,new_node});
                    }
                }
            }
        }
        
        return ans;
    }
};
