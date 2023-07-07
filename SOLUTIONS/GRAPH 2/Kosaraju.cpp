#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &vis, vector<vector<int>> adj,stack<int> &st) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) {
            dfs(it, vis, adj, st);
        }
    }

    st.push(node);
}

void dfs2(int node, vector<int> &vis, vector<int> adjT[]) {
    vis[node] = 1;
    for (auto it : adjT[node]) {
        if (!vis[it]) {
            dfs2(it, vis, adjT);
        }
    }
}

vector<vector<int>> stronglyConectedComponents(int V, vector<vector<int>> &edges)
{
    vector<int> vis(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, edges, st);
            }
        }

        vector<int> adjT[V];
        for (int i = 0; i < V; i++) {
            vis[i] = 0;
            for (auto it : edges[i]) {
                adjT[it].push_back(i);
            }
        }
        vector<vector<int>> scc;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!vis[node]) {
                scc[0].push_back(node);
                dfs2(node, vis, adjT);
            }
        }
        return scc;
}
