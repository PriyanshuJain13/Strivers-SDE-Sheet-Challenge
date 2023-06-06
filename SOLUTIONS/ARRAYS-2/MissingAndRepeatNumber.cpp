#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	unordered_map<int,int> mp;
	int rep;
	int miss;
	for(int i = 1;i <= n;i++)
	{
		mp[i] = 0;
	}
	for(auto it:arr)
	{
		mp[it]++;
		if(mp[it] == 2)
		{
			rep = it;
		}
	}

	for(int i = 1;i <= n;i++)
	{
		if(mp[i] == 0)
		{
			miss = i;
		}
	}
	pair<int,int> ans;
	ans.second = rep;
	ans.first = miss;

	return ans;
}
