#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<int> pq;
    for(auto arr:kArrays)
    {
        for(auto it:arr)
        {
            pq.push(it);
        }
    }

    vector<int> ans;
     while (!pq.empty()) {
        ans.push_back(pq.top());
        pq.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
