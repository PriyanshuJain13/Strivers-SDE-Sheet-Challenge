class Solution {
    void solve(string &s,int ind,vector<string>& temp,vector<vector<string>> &ans)
    {
        int n = s.length();
        if(ind == n)
        {
            ans.push_back(temp);
        }else{
            for(int i = ind;i < n;i++)
            {
                if(isPalindrome(s,ind,i) == true)
                {
                    temp.push_back(s.substr(ind,i-ind+1));
                    solve(s,i+1,temp,ans);
                    temp.pop_back();
                }
            }
        }
    }

    bool isPalindrome(string s,int start,int end)
    {
        while(start < end)
        {
            if(s[start] != s[end])
            {
                return false;
            }
            start++;
            end--;
        }

        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(s,0,temp,ans);

        return ans;
    }
};
