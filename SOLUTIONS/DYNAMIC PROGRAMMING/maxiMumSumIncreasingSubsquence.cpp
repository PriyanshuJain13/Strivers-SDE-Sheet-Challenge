class Solution{
	public:
	int maxSumIS(int arr[], int n)  
	{  
	    vector<int> dp(n);
	    for(int i = 0;i < n;i++)
	    {
	        dp[i] = arr[i];
	    }
	    for(int i = 0;i < n;i++)
	    {
	        for(int j = 0;j< i;j++)
	        {
	            if(arr[i] > arr[j] && dp[i] < dp[j] + arr[i])
	            {
	                dp[i] = dp[j] + arr[i];
	            }
	        }
	    }
	    int ans = INT_MIN;
	    for(auto it:dp)
	    {
	        ans = max(ans,it);
	    }
	    return ans;
	}  
};
