class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int rows = matrix.size(), cols = matrix[0].size();
        unordered_set<int> r, c;

        int cnt = 0;

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){

                if(matrix[i][j] == 0){
                    cnt++;
                    r.insert(i);
                    c.insert(j);
                }
            }
        }

        if(cnt == rows*cols) return;

        //traversing rows having zeroes
        for(auto it: r){

            for(int i=0; i<cols; i++){
                matrix[it][i] = 0;
            }
        }

        //traversing cols having zeroes
        for(auto it: c){

            for(int i=0; i<rows; i++){
                matrix[i][it] = 0;
            }
        }

        return ;
    }
};