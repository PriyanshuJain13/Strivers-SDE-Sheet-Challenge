class Solution {

    int f(vector<int>& coins,int amount,int n,vector<vector<int>>& dp)
    {
        if(n == 0)
        {
            if(amount % coins[n] == 0)
            {
                return amount/coins[n];
            }else{
                return 1e9;
            }
        }

        if(dp[n][amount] != -1)
        {
            return dp[n][amount];
        }

        int take = INT_MAX;
        int notTake = 0 + f(coins,amount,n-1,dp);
        if(coins[n] <= amount)
        {
            take = 1 + f(coins,amount - coins[n],n,dp);
        }
        return dp[n][amount] = min(take,notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = f(coins,amount,n-1,dp);
        if(ans >= 1e9)
        {
            return -1;
        }
        return ans;
    }
};
