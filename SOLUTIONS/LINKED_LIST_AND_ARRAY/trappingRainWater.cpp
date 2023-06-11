class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n,0);
        vector<int> right(n,0);

        left[0] = height[0];
        right[n-1] = height[n-1];

        int leftHigh = left[0];
        int rightHigh = right[n-1];

        for(int i = 1;i < n; i++)
        {
            if(height[i] > leftHigh)
            {
                leftHigh = height[i];
            }
            left[i] = leftHigh;

            if(height[n-i-1] > rightHigh)
            {
                rightHigh = height[n-i-1];
            }
            right[n-i-1] = rightHigh;
        }
        int ans = 0;
        for(int i = 0;i < n;i++)
        {
            ans += (min(left[i],right[i]) - height[i]);
        }

        return ans;
    }
};
