class Solution {

    int f(vector<vector<int>> &grid, int m, int n, vector<vector<int>> &dp)
    {
        if (m == 0 && n == 0)
        {
            return grid[m][n];
        }

        if (m < 0 || n < 0)
        {
            return 1e9;
        }

        if (dp[m][n] != -1)
            return dp[m][n];

        int up = 1e9;
        int left = 1e9;
        if (m - 1 >= 0)
            up = grid[m][n];
        if (n - 1 >= 0)
            left = grid[m][n];

        return dp[m][n] = min(up + f(grid, m - 1, n,dp), left + f(grid, m, n - 1,dp));
    }

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int ans =  f(grid, m - 1, n - 1,dp);
        return ans;
    }
};
