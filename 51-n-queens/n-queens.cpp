class Solution {

    void solve(int col, int n, vector<string> &board, vector<vector<string>> &ans,
     vector<int> &leftdiag, vector<int> &upperleft, vector<int> &lowerleft){

        //base condn
        if(col >= n){
            ans.push_back(board);
            return;
        }

        for(int r=0; r<n; r++){

            if(leftdiag[r] == 0 && upperleft[n-1+col-r] == 0 && lowerleft[r+col] == 0){
                //queen can be placed here
                board[r][col] = 'Q';
                leftdiag[r] = 1;
                upperleft[n-1+col-r] = 1;
                lowerleft[r+col] = 1;

                solve(col+1, n, board, ans, leftdiag, upperleft, lowerleft);

                board[r][col] = '.';
                leftdiag[r] = 0;
                upperleft[n-1+col-r] = 0;
                lowerleft[r+col] = 0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');

        for(int i=0; i<n; i++){
            board[i] = s;
        }

        vector<int> leftdiag(n,0);
        vector<int> upperleft(2*n - 1, 0);
        vector<int> lowerleft(2*n - 1 , 0);

        solve(0, n, board, ans, leftdiag, upperleft, lowerleft);
        return ans;
    }
};