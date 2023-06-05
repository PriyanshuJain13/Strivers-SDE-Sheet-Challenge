#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    long long maxi = INT_MIN;
    long long lastMax = 0;
    for(long long i = 0;i < n;i++)
    {
        lastMax = lastMax + arr[i];
        if(maxi < lastMax)
        {
            maxi = lastMax;
        }
        if(lastMax < 0)
        {
            lastMax = 0;
        }
    }
    if(maxi < 0)
    {
        return 0;
    }
    return maxi;
}
