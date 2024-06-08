class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size(), m = matrix[0].size();
        int st = 0, end = n*m - 1;

        while(st <= end){

            int mid = st + (end - st)/2;
            int row = mid/m, col = mid%m;

            if(target < matrix[row][col]){
                end = mid-1;
            }
            else if(target > matrix[row][col]){
                st = mid+1;
            }
            else{
                return true;
            }
        }

        return false;
    }
};