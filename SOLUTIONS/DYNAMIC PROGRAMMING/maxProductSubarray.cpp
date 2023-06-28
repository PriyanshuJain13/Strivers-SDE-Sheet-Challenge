class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minTemp = nums[0], maxTemp=nums[0];        
        int ans = nums[0];
        for(int i = 1; i < nums.size(); i++){
            vector<int> temp={nums[i], minTemp*nums[i], maxTemp*nums[i]};
            minTemp = *min_element(temp.begin(), temp.end());
            maxTemp = *max_element(temp.begin(), temp.end());
            ans = max(ans, maxTemp);
        }
        return ans;
    }
};
