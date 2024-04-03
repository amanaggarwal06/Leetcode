
typedef pair<int, pair<int,int>> pp;
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
         
         int n = grid.size();
         vector<vector<int>> dist(n, vector<int>(n,1e9));

        //edge case
        if(grid[0][0] != 0) return -1;

        priority_queue<pp, vector<pp>, greater<pp>> minh;

        minh.push({0,{0,0}});
        dist[0][0] = 0;


        while(!minh.empty()){

            auto it = minh.top();
            int d = it.first;
            int r = it.second.first, c = it.second.second;
            minh.pop();

            for(int i=-1; i<=1; i++){
                for(int j=-1; j<=1; j++){

                    int nrow = r + i;
                    int ncol = c + j;

                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol] == 0){

                        if(d + 1 < dist[nrow][ncol]){
                            dist[nrow][ncol] = d + 1;
                            minh.push({dist[nrow][ncol], {nrow, ncol}});
                        }
                    }
                }
            }

            
        }

        if(dist[n-1][n-1] == 1e9) return -1;

        return dist[n-1][n-1] + 1;
    }
};