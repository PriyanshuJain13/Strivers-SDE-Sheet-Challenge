class Solution
{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        pq.push({0,S});
        vector<int>ans(V,1e9);
        ans[S]=0;
        
        while(!pq.empty())
        {
            int frontNode = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            
            for(auto it: adj[frontNode]){
                int new_node = it[0];
                int new_dist = it[1];
                if(dist+new_dist < ans[new_node])
                {
                    ans[new_node] = dist + new_dist;
                    pq.push({ans[new_node],new_node});
                }    
            }
        }
        return ans;
    }
};
