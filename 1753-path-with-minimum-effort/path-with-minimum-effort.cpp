typedef pair<int, pair<int,int>> pp;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        priority_queue<pp, vector<pp>, greater<pp>> minh;

        minh.push({0, {0,0}});

        int del_row[] = {-1,0,1,0};
        int del_col[] = {0,-1,0,1};

        while(!minh.empty()){

            auto it = minh.top(); minh.pop();
            int effort = it.first;
            int r = it.second.first, c = it.second.second;

            if(r == n-1 && c == m-1){
                return effort;
            }

            for(int i=0 ;i<4; i++){

                int nrow = r + del_row[i];
                int ncol = c + del_col[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){

                    int diff = abs(heights[nrow][ncol] - heights[r][c]);
                    
                    int max_diff = max(diff, effort);

                    if(max_diff < dist[nrow][ncol]){
                        dist[nrow][ncol] = max_diff;
                        minh.push({max_diff, {nrow, ncol}});
                    }
                }
            }
        }

        return -1;
    }
};