class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int minLen = INT_MAX;
        for(auto it:strs)
        {
            int n = it.length();
            minLen = min(n,minLen);
        }

        for(int i = 0;i < minLen;i++)
        {
            bool temp = true;
            for(int j = 0;j < strs.size() - 1;j++)
            {
                if(strs[j][i] != strs[j+1][i])
                {
                    temp = false;
                    break;
                }
            }
            if(temp == true)
            {
                ans += strs[0][i];
            }else{
                break;
            }
        }

        return ans;
    }
};
