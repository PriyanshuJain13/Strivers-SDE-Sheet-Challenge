class Solution 
{
    static bool func(Job a,Job b)
    {
        return a.profit > b.profit;
    }
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,func);
        
        vector<int> cur(n,-1);
        int count = 0;
        int totalProfit = 0;
        for(int i = 0;i < n;i++)
        {
            int job = arr[i].id;
            int deadLine = arr[i].dead;
            int profit = arr[i].profit;
            
            int j = deadLine - 1;
            while(j >= 0 && cur[j] == 0)
            {
                j--;
            }
            
            if(j >= 0)
            {
                totalProfit+= profit;
                cur[j] = 0;
                count++;
            }
        }
        
        vector<int> ans = {count,totalProfit};
        return ans;
    } 
};
