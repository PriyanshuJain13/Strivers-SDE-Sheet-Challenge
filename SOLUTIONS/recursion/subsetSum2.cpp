class Solution {
    void solve(vector<int>& nums,int ind,vector<vector<int>>& ans,vector<int>& temp)
    {
        ans.push_back(temp);
        for(int i = ind;i < nums.size();i++)
        {
            if(i != ind && nums[i] == nums[i-1]) continue;
            temp.push_back(nums[i]);
            solve(nums,i+1,ans,temp);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(nums,0,ans,temp);

        return ans;
    }
};
