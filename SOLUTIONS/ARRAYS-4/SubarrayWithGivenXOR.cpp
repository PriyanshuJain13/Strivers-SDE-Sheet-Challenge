#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int m)
{
    int n = arr.size();
    unordered_map <int, int> mp;
	mp[0] = 1;
	int ans = 0, curSum = 0;
	for (int i = 0; i < n; i++)
	{
		curSum ^= arr[i];
		if (mp[curSum ^ m] > 0)
			ans += mp[curSum ^ m];
		mp[curSum]++;
	}
	return ans;
}
