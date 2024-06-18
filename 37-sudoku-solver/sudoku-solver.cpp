class Solution {

    bool isValid(int r, int col, vector<vector<char>> &board, char ch){

        for(int i=0; i<9; i++){

            //rows
            if(board[i][col] == ch) return false;

            //cols
            if(board[r][i] == ch) return false;

            //3x3 grid
            if(board[3*(r/3)+ (i/3)][3*(col/3) + (i%3)] == ch) return false;
        }
        return true;
    }

    bool solve(int row, int col , vector<vector<char>> &board){

        int r = row, c = col;
        //base condn
        if(r>= 9 || c >=9) return true;

        while(r<9){
            
            while(c<9){
            if(board[r][c] == '.'){
                for(char ch = '1'; ch<= '9'; ch++){

                    if(isValid(r, c, board, ch)){
                        board[r][c] = ch;
                        
                        if(solve(r,c, board)){
                            return true;
                        }
                        else{
                            board[r][c] = '.';
                        }
                    }
                }
                return false;
            }
            c++;
            }
            r++;
            c = 0;
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        
        int r=0, c=0;
        bool flag = solve(r, c, board);
        return;
    }
};