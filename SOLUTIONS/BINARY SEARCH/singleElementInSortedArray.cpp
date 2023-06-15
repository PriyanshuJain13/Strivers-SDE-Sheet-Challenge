class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        for(int i= 0;i < arr.size()-1;i++)
        {
            arr[i+1] = arr[i+1]^arr[i];
        }

        return arr[arr.size()-1];
    }
};
