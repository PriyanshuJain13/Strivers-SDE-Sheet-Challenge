class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        sort(nums.begin(),nums.end());
        vector<vector<int>> vec;
        map<vector<int>,int>map;
      
        for(int i=0;i<nums.size();i++){
             for(int j=i+1;j<nums.size();j++)
             {
                
                       int start=j+1;
                       int end = nums.size()-1;
                       while(start<end){
                       long long currentsum =nums[start]+nums[end]+nums[i]*1ll+nums[j];
                        if(currentsum==target){
                            vector<int>ans;
                            ans.push_back(nums[i]);
                            ans.push_back(nums[j]); 
                            ans.push_back(nums[start]);
                            ans.push_back(nums[end]);
                            if(map[ans]==0){
                                map[ans]=1;
                                vec.push_back(ans);
                             }
                            start++;
                        }
                        else if(currentsum<target){
                            start++;
                        }
                        else{
                            end--;
                        }
                       }
            }
        }
     return vec;   
    }
};
