#include <bits/stdc++.h>

vector<string> solve(string& s,int ind,unordered_set<string>& dict,unordered_map<int,vector<string>>& dp,int size)
{
    if(ind == size)
    {
        return {""};
    }

    if(dp.find(ind) != dp.end())
    {
        return dp[ind];
    }

    vector<string> sub,full;

    string word = "";

    for(int j = ind;j < size;j++)
    {
        word += s[j];
        if(dict.count(word) == 0)
        {
            continue;
        }

        sub = solve(s,j+1,dict,dp,size);

        for(int i = 0;i < sub.size();i++)
        {
            if(sub[i].size() != 0)
            {
                string temp = word;
                temp.append(" ");
                temp.append(sub[i]);
                sub[i] = temp;
            }else{
                sub[i] = word;
            }
        }

        for(int i = 0;i < sub.size();i++)
        {
            full.push_back(sub[i]);
        }
    }

    dp[ind] = full;

    return dp[ind];
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    unordered_map<int,vector<string>> dp;
    unordered_set<string> dict;

    for(int i = 0;i < dictionary.size();i++)
    {
        dict.insert(dictionary[i]);
    }

    return solve(s,0,dict,dp,s.size());
}
