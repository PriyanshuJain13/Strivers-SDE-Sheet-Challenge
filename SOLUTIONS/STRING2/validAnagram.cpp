class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.length() != t.length())
        {
            return false;
        }
        vector<int> count(26);
        for(int i = 0 ; i < s.size(); i++)
        {
            count[s[i] - 'a']++;
        }
        for(int i = 0 ; i < t.size(); i++)
        {
            count[t[i] - 'a']--;
            if(count[t[i] - 'a'] < 0)
            {
                return false;
            }
        }
        return true;
    }
};
