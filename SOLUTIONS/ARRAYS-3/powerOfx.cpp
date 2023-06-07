class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long temp = abs(n);

        while(temp)
        {
            if(temp % 2 == 0)
            {
                x = x*x;
                temp = temp/2;
            }else{
                temp = temp - 1;
                ans = ans*x;
            }
        }

        if(n < 0)
        {
            ans = 1/ans;
        }

        return ans;
    }
};
