class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i = 0;i < n;i++)
        {
            mp[nums[i]] = true;
        }

        for(int i = 0;i < n;i++)
        {
            if(mp.count(nums[i] - 1) > 0)
            {
                mp[nums[i]] = false;
            }
        }

        int ans = 0;
        for(int i = 0;i < n;i++)
        {
            if(mp[nums[i]] == true)
            {
                int j = 0;
                int count = 0;
                while(mp.count(nums[i] + j) > 0)
                {
                    j++;
                    count++;
                }
                ans = max(ans,count);
            }
        }
        return ans;
    }
};
