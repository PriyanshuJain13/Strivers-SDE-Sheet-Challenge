class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        map<int,int> mp;
        s.push(INT_MAX);
        for(int i = nums2.size()-1;i >= 0;i--)
        {
            int curr = nums2[i];

            while(s.top() <= curr)
            {
                s.pop();
            }
            mp[nums2[i]] = s.top() == INT_MAX?-1:s.top();
            s.push(curr);
        }

        vector<int> ans;
        for(int i = 0;i < nums1.size();i++)
        {
            ans.push_back(mp[nums1[i]]);
        }

        return ans;
    }
};
