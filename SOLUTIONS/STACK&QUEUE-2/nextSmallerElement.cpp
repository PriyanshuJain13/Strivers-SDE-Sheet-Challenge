#include<bits/stdc++.h>

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(INT_MAX);
    vector<int> ans;
    for(int i = n-1;i >= 0;i--)
    {
        while(s.top() >= arr[i] && s.top() != INT_MAX)
        {
            s.pop();
        }
        if(s.top() == INT_MAX)
        {
            ans.push_back(-1);
        }else{
            ans.push_back(s.top());
        }

        s.push(arr[i]);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
