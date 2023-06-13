class Solution {
public:
    string getPermutation(int n, int k) {
        string ans = "";
        int fac = 1;
        vector<int> num;
        for(int i = 1;i < n;i++)
        {
            fac = fac*i;
            num.push_back(i);
        }

        num.push_back(n);

        k = k - 1;
        while(true)
        {
            ans += to_string(num[k/fac]);
            num.erase(num.begin()+k/fac);
            if(num.size() == 0)
            {
                break;
            }
            k = k%fac;
            fac = fac/num.size();
        }

        return ans;
    }
};
