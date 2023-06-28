class Solution {

    int f(string& s1,string& s2,int n1 ,int n2,vector<vector<int>> &dp)
    {
        if(n1 < 0 || n2 < 0)
        {
            return 0;
        }

        if(dp[n1][n2] != -1)
        {
            return dp[n1][n2];
        }

        if(s1[n1] == s2[n2])
        {
            return dp[n1][n2] = 1 + f(s1,s2,n1-1,n2-1,dp);
        }else{
            return dp[n1][n2] = 0 + max(f(s1,s2,n1,n2-1,dp),f(s1,s2,n1-1,n2,dp));
        }
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();

        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return f(text1,text2,n1-1,n2-1,dp);
    }
};
