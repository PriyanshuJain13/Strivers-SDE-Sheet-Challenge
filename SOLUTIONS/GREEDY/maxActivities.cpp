#include <bits/stdc++.h>

int maximumActivities(vector<int> &start, vector<int> &finish) {
    vector<pair<int,int>> temp;
    int n = start.size();
    for(int i = 0;i < n;i++)
    {
        temp.push_back({finish[i],start[i]});
    }
        
    sort(temp.begin(),temp.end());
    int ans = 0;
    int end;
    for(int i = 0;i < n;i++)
    {
        if(i == 0)
        {
            ans++;
            end = temp[i].first;
        }else{
            if(temp[i].second >= end)
            {
                ans++;
                end = temp[i].first;
            }
        }
    }

    return ans;
}
