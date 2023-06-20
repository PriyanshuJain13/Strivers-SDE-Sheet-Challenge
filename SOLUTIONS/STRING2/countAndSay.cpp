class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string temp = countAndSay(n-1);
        string ans = "";
        int i = 0;
        while(i < temp.size()){
            char ch = temp[i];
            int count = 0;
            while(temp[i] == ch && i < temp.size())
            {
                count++;
                i++;
            }
            ans.push_back(count + '0');
            ans.push_back(temp[i-1]);
        }

        return ans;
    }
};
