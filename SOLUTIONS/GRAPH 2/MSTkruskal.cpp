class disjoint{
    vector<int>rank;
    vector<int>parent;
    public:
    disjoint(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    
    int find(int n){
        if(n==parent[n])return n;
       
         return parent[n]=find(parent[n]);
        
    }
    
    void unionbyrank(int a,int b){
        int u=find(a);
        int v=find(b);
        if(u==v)return;
        if(rank[u]>rank[v]){
            parent[v]=u;
        }
        else if(rank[v]>rank[u]){
            parent[u]=v;
        }
        else{
            parent[u]=v;
            rank[v]++;
        }
    }
   
};

class Solution
{
	public:
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>>edges;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                int u=i;
                int v=it[0];
                int wt=it[1];
                
                edges.push_back({wt,{u,v}});
            }
        }
        
        
        sort(edges.begin(),edges.end());
        disjoint ds(V);
        int w=0;
        for(auto i:edges){
            int u=i.second.first;
            int v=i.second.second;
            int wt=i.first;
            if(ds.find(u)!=ds.find(v)){
                ds.unionbyrank(u,v);
                w+=wt;
            }
        }
        
     return w;   
        
    }
};
