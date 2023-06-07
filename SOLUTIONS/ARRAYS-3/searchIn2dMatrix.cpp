class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n == 0)
        {
            return false;
        }
        int m = matrix[0].size();

        int l = 0;
        int h = m*n;
        while(l < h)
        {
            int mid = (l+h)/2;
            if(matrix[mid/m][mid%m] == target)
            {
                return true;
            }else if(matrix[mid/m][mid%m] > target)
            {
                h = mid;
            }else{
                l = mid+1;
            }
        }

        return false;
        
    }
};
