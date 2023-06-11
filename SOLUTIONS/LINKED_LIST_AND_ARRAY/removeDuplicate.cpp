class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int uni = 0;
        int num;
        for(int i = 0;i < nums.size();i++)
        {
            if(i == 0)
            {
                num = nums[i];
                uni = 1;
            }else{
                if(nums[i] != num)
                {
                    nums[uni] = nums[i];
                    uni++;
                    num = nums[i];
                }
            }
        }

        return uni;
    }
};
