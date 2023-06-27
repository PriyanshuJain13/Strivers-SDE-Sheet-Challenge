class Solution
{
    int f(int w,int wt[],int val[],int index,vector<vector<int>> &dp)
    {
        if(index == 0)
        {
            if(wt[index] <= w)
            {
                return val[index];
            }else{
                return 0;
            }
        }
        
        if(dp[index][w] != -1)
        {
            return dp[index][w];
        }
        
        int notTaken = 0 + f(w,wt,val,index-1,dp);
        int taken = INT_MIN;
        
        if(wt[index] <= w)
        {
            taken = val[index] + f(w-wt[index],wt,val,index-1,dp);
        }
        
        return dp[index][w] = max(taken,notTaken);
    }
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>> dp(n+1,vector<int>(W+1,-1));
        int ans = f(W,wt,val,n-1,dp);
        
        return ans;
    }
};
