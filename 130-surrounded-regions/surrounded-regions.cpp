class Solution {

    void dfs(int r, int c, vector<vector<int>> &visited, vector<vector<char>> &mat){

        //base condition
        if(visited[r][c]){
            return;
        }

        int n = mat.size(), m = mat[0].size();
        visited[r][c] = 1;

        int del_row[] = {-1,0,1,0};
        int del_col[] = {0,1,0,-1};

        for(int i=0; i<4; i++){
            int nrow = r + del_row[i];
            int ncol = c + del_col[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && mat[nrow][ncol] == 'O' && !visited[nrow][ncol]){
                dfs(nrow, ncol, visited, mat);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        
        int n = board.size(), m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m,0));

        //1st row and last row
        for(int j=0; j<m; j++){

            if(board[0][j] == 'O'){
                dfs(0,j, visited, board);
            }

            if(board[n-1][j] == 'O'){
                dfs(n-1, j, visited, board);
            }
        }

        //1st col and last col
        for(int i=0; i<n; i++){

            if(board[i][0] == 'O'){
                dfs(i,0, visited, board);
            }

            if(board[i][m-1] == 'O'){
                dfs(i, m-1, visited, board);
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){

                if(board[i][j] == 'O' && !visited[i][j]){
                    board[i][j] = 'X';
                }
            }
        }

        return;
    }
};