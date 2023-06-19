class Solution {
public:
    int myAtoi(string s) {
        int ind = 0;
        while(s[ind] == ' ')
        {
            ind++;
        }

        bool neg = false;
        bool pos = false;
        if(s[ind] == '-')
        {
            neg = true;
            ind++;
        }else if(s[ind] == '+')
        {
            pos = true;
            ind++;
        }
        double ans = 0;
        while(ind < s.length() && s[ind] >= '0' && s[ind] <= '9')
        {
            ans = ans*10 + (int(s[ind]) - 48);
            ind++;
        }

        if(neg == true)
        {
            ans = -1*ans;
        }

        if(ans > INT_MAX)
        {
            ans = INT_MAX;
        }else if(ans < INT_MIN)
        {
            ans = INT_MIN;
        }

        return int(ans);

    }
};
