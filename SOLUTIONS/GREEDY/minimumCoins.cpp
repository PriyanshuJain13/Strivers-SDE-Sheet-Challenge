#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    vector<int> temp = {1,2,5,10,20,50,100,500,1000};
    int ans = 0;
    int n = temp.size();
    for(int i = n-1;i >= 0;i--)
    {
        while(amount >= temp[i])
        {
            ans++;
            amount = amount - temp[i];
        }
    }

    return ans;

}
