class Solution {
public:
    bool solve(vector<vector<char>>&G, int i, int j)
    {
        if(i<0||j<0||i>=G.size()||j>=G[0].size())
        {
            return true;        
        }
        if (G[i][j] == '0')
        {
            return true;        
        }

        G[i][j]='0';
        
        bool p=solve(G,i+1,j);
        bool q=solve(G,i,j+1);
        bool r=solve(G,i-1,j);
        bool s=solve(G,i,j-1);

        return (p && q && r && s);
    }

    int numIslands(vector<vector<char>>& grid) {
        int k=0;
        for (int i=0;i<grid.size();i++)
        {
            for (int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    if(solve(grid,i,j))
                    {
                       k++;
                    }
                }  
            }  
        }
                 
        return k;
    }
    
};
