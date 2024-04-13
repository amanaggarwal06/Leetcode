class Solution {

    void dfs(int sr, int sc, vector<vector<int>> &result, int &ini_color,int &new_color){

        int t_rows = result.size(), t_cols = result[0].size();

        //base condition
        if(sr < 0 || sr >= t_rows || sc<0 || sc>=t_cols || result[sr][sc] == new_color ||result[sr][sc] != ini_color){
            return;
        }

        
        int del_row[] = {-1,0,1,0};
        int del_cols[] = {0,1,0,-1};

        result[sr][sc] = new_color;

        for(int i=0; i<4; i++){

            int nrow = sr + del_row[i];
            int ncol = sc + del_cols[i];

            if(nrow>=0 && nrow<t_rows && ncol >=0 && ncol < t_cols && result[nrow][ncol] == ini_color){
                dfs(nrow, ncol, result, ini_color, new_color);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        vector<vector<int>> result = image;

        int t_rows = image.size();
        int t_cols = image[0].size();
        int ini_color = image[sr][sc];

        // //bfs
        // queue<pair<int,int>> q;
        // q.push({sr,sc});

        // int del_rows[] = {-1,0,1,0};
        // int del_cols[] = {0,1,0,-1};

        // while(!q.empty()){

        //     auto it = q.front();
        //     q.pop();

        //     int r = it.first;
        //     int c = it.second;

        //     result[r][c] = color;
        //     for(int i=0; i<4; i++){
                
        //         int nrow = r + del_rows[i];
        //         int ncol = c + del_cols[i];

        //         if(nrow >= 0 && nrow < t_rows && ncol >=0 && ncol < t_cols && result[nrow][ncol] == ini_color ){
        //             q.push({nrow, ncol});
        //              result[nrow][ncol] = color;

        //         }
        //     }
        // }

        // return result;

        //dfs
        dfs(sr,sc, result, ini_color, color);
        return result;
    }
};