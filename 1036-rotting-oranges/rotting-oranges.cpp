class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        //bfs approach
        int time = 0; int freshcount = 0;
        queue<pair<pair<int,int>, int>> q;
        int rows = grid.size();
        int cols = grid[0].size();

        int visited[rows][cols];

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){

                if(grid[i][j] == 2){
                    q.push({{i,j}, 0});
                    visited[i][j] = 2;
                }
                else if(grid[i][j] == 1){
                    visited[i][j] = 0;
                    freshcount++;
                }
                else{
                    visited[i][j] = 0;
                }
            }
        }

        int del_row[] = {-1,0,1,0};
        int del_col[] = {0,-1,0,1};
        int cnt = 0;

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();

            time = max(time, t);
            for(int i=0; i<4; i++){

                int nrow = r + del_row[i];
                int ncol = c+ del_col[i];

                if(nrow >= 0 && nrow< rows && ncol>=0 && ncol<cols && grid[nrow][ncol] == 1 && visited[nrow][ncol] != 2){
                    q.push({{nrow, ncol}, t+1});
                    visited[nrow][ncol] = 2;
                    cnt++;
                }
            }
            
        }

        if(freshcount != cnt) return -1;
        return time;

    }
};