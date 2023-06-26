#include <bits/stdc++.h> 
vector<int> countDistinctElements(vector<int> &arr, int k) 
{   
    int n = arr.size();
    unordered_map<int, int> mp;
    vector<int> ans;
    int temp = 0;

    for(int i = 0; i < k; i++) 
    {
        if (mp[arr[i]] == 0)
        {
            temp++;
        }
       
        mp[arr[i]] += 1;
    }
    ans.push_back(temp);

    for(int i = k; i < n; i++) {

        if (mp[arr[i - k]] == 1)
        {
            temp--;
        }

        mp[arr[i - k]] -= 1;
 
        if (mp[arr[i]] == 0)
        {
            temp++;
        }
        mp[arr[i]] += 1;
        ans.push_back(temp);
    }
    
    return ans;
}
