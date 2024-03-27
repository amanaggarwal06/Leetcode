class Solution {

    void dfs(int r, int c, vector<vector<int>> &vis, vector<vector<int>> &grid){

        vis[r][c] = 1;
        int n = grid.size(), m = grid[0].size();

        int del_row[] = {-1,0,1,0};
        int del_col[] = {0,1,0,-1};

        for(int i=0; i<4; i++){

            int nrow = r + del_row[i];
            int ncol = c + del_col[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] == 1 && !vis[nrow][ncol]){
                dfs(nrow, ncol, vis, grid);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        // traverse all boundary and mark all 1's which are connected to the boundary
        // traverse all non-boundary and cnt all the 1;s which are not marked
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m,0));

        for(int j=0; j<m; j++){
            if(grid[0][j] ==  1){
                dfs(0,j,visited, grid);
            }

            if(grid[n-1][j] == 1){
                dfs(n-1, j, visited, grid);
            }
        }

        //!st col and last col
        for(int i=0; i<n; i++){

            if(grid[i][0] == 1){
                dfs(i,0,visited,grid);
            }

            if(grid[i][m-1] == 1){
                dfs(i, m-1, visited, grid);
            }
        }

        //traverse all non-boundary cells
        int cnt = 0;
        for(int i=1; i<n-1; i++){
            for(int j=1; j<m-1; j++){

                if(grid[i][j] == 1 && !visited[i][j]){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};