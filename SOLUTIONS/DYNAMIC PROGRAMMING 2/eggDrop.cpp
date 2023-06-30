class Solution
{
    public:
    int eggDrop(int n, int k) 
    {
        vector<int> prev(k+1, 0), cur(k+1, 0);
        
        
        for(int i = 0; i <= k; i++)
            prev[i] = i;
    
        
        for(int i = 2; i <= n; i++)
        {
            for(int flr = 1; flr <= k; flr++)
            {
                int mn = INT_MAX;
                for(int f = 1; f <= flr; f++)
                {
                    int temp = 1 + max(prev[f - 1], cur[flr - f]);
                    mn = min(mn, temp);
                }
                cur[flr] = mn;
            }
            prev = cur;
        }
        
        return prev[k];
    }
};
