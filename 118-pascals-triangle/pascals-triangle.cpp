class Solution {

    vector<int> giveRow(int rownum){

        int res = 1;
        vector<int> ans;
        ans.push_back(res);

        for(int col = 1; col< rownum; col++){
            res = res*(rownum-col);
            res = res/col;
            ans.push_back(res);
        }
        return ans;
    }
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ans;
        for(int i = 1; i<= numRows; i++){

            ans.push_back(giveRow(i));
        }
        return ans;
        
    }
};