class Solution {
    bool f(vector<int>& arr,int n,int k)
    {
        vector<bool> prev(k+1,false);
    
        prev[0] = true;
        
        if(arr[0]<=k)
            prev[arr[0]] = true;
        
        for(int ind = 1; ind<n; ind++){
            vector<bool> cur(k+1,false);
            cur[0] = true;
            for(int target= 1; target<=k; target++){
                bool notTaken = prev[target];
        
                bool taken = false;
                    if(arr[ind]<=target)
                        taken = prev[target-arr[ind]];
            
                cur[target]= notTaken||taken;
            }
            prev = cur;
        }
        
        return prev[k];
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for(int i = 0;i < n;i++)
        {
            sum+=nums[i];
        }

        if(sum % 2 != 0) return false;
        int target = sum/2;

        bool ans = f(nums,n,target);

        return ans;
    }
};
