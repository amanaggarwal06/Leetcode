class Solution {

    void dfs(int r, int c, vector<vector<int>> & grid, vector<vector<int>> &vis, int &ans){

        //base condition
        if(vis[r][c] == 1){
            return;
        }

        vis[r][c] = 1;
        int cnt = 0;
        int del_row[] = {-1,0,1,0};
        int del_col[] = {0,1,0,-1};

        for(int i=0; i<4; i++){

            int nrow = r + del_row[i], ncol = c + del_col[i];

            if(nrow >=0 && nrow < grid.size() && ncol >=0 && ncol < grid[0].size() && grid[nrow][ncol] == 1){

                if(!vis[nrow][ncol]){
                    dfs(nrow, ncol, grid, vis, ans );
                }
                
                cnt++;
            }
        }

        ans += (4-cnt);
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int ans = 0;
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){

                if(grid[i][j] == 1){
                    dfs(i,j, grid, vis, ans);
                    break;
                }
            }
        }

        return ans;
    }
};