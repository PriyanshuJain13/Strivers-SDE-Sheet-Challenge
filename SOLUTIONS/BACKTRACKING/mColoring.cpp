//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    void solve(bool graph[101][101], int m, int n,int i,bool &ans,int color[])
    {
        if(i == n)
        {
            ans = true;
            return;
        }
        if(!ans)
        {
            vector<int> temp(m+1,1);
            for(int j = 0;j < n;j++)
            {
                if(graph[i][j] && color[j])
                {
                    temp[color[j]] = 0;
                }
            }
            for(int j = 1;j <= m;j++)
            {
                if(temp[j])
                {
                    color[i] = j;
                    solve(graph,m,n,i+1,ans,color);
                    color[i] = 0;
                    if(ans)
                    {
                        return ;
                    }
                }
            }
        }
    }
public:
    bool graphColoring(bool graph[101][101], int m, int n) {
        int colour[20];
        bool ans = false;
        for(int i = 0;i < n;i++)
        {
            colour[i] = 0;
        }
        solve(graph,m,n,0,ans,colour);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

