#include <bits/stdc++.h> 
void sortStack(stack<int> &st)
{
	vector<int> temp;
	while(!st.empty())
	{
		temp.push_back(st.top());
		st.pop();
	}

	sort(temp.begin(),temp.end());

	for(auto it: temp)
	{
		st.push(it);
	}


}
