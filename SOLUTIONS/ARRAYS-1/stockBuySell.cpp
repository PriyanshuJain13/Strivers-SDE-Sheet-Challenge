#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int minBuy = prices[0];
    int maximumProfit = 0;
    for(int i = 0;i < prices.size();i++)
    {
        minBuy = min(prices[i],minBuy);
        maximumProfit = max(maximumProfit,prices[i] - minBuy);
    }

    return maximumProfit;
}
