class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans = -1;
        int max = 0;
        for(auto it:nums)
        {
            mp[it]++;
            if(mp[it] > max)
            {
                ans = it;
                max = mp[it];
            }
        }

        if(max > (nums.size()/2))
        {
            return ans;
        }else{
            return -1;
        }
    }
};
