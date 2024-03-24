class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int trows = mat.size(), tcols = mat[0].size();
        vector<vector<int>> visited(trows, vector<int>(tcols, 0));

        vector<vector<int>> ans(trows, vector<int>(tcols,0));
        queue< pair< pair<int,int> , int> > q;
        
        for(int i=0; i<trows; i++){
            for(int j=0; j<tcols; j++){

                if(mat[i][j] == 0) {
                    q.push({{i,j},0});
                    visited[i][j] = 1;
                }
            }
        }

        while(!q.empty()){

            int r = q.front().first.first;
            int c = q.front().first.second;
            int dis = q.front().second;
            q.pop();

            ans[r][c] = dis;

            int del_row[]= {-1,0,1,0};
            int del_col[] = {0,1,0,-1};

            for(int i=0; i<4; i++){

                int nrow = r + del_row[i];
                int ncol = c + del_col[i];

                if(nrow >=0 && nrow< trows && ncol>=0 && ncol< tcols && !visited[nrow][ncol]){

                    q.push({{nrow,ncol}, dis+1});
                    visited[nrow][ncol] = 1;
                }
            }
        }

        return ans;
    }
};