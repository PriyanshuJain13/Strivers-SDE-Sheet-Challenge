class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> ans;
        int n = nums.size();
        for(auto it: nums)
        {
            if(mp[it] != -1)
            {
                mp[it]++;
                if(mp[it] > (n/3))
                {
                    ans.push_back(it);
                    mp[it] = -1;
                }
            }
            
        }

        return ans;
    }
};
