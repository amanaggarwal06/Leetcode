class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();

        for(int i=0; i<rows-1; i++){
            for(int j=i+1; j<cols; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        //rev every row
        for(int col = 0; col<cols; col++){
            reverse(matrix[col].begin(), matrix[col].end());
        }

        return;
    }
};