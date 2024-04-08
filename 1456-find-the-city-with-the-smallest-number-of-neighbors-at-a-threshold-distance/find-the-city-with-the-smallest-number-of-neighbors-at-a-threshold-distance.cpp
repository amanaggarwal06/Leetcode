class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        for(int i=0; i<edges.size(); i++){
            
            int start = edges[i][0], end = edges[i][1], cost = edges[i][2];
            dist[start][end] = cost;
            dist[end][start] = cost;
        }

        for(int i=0; i<n; i++) dist[i][i] = 0;

        for(int via = 0; via<n; via++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){

                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }

        int mini = INT_MAX, node = -1;
        for(int i=0; i<n; i++){

            int cnt = 0;
            for(int j=0; j<n; j++){

                if(dist[i][j] != 0 && dist[i][j] != 1e9 && dist[i][j] <= distanceThreshold){
                    cnt++;
                }

            }

            if(mini >= cnt){
                mini = cnt; node = i;
            }

        }

        return node;
    }
};