
typedef pair<int,int> pp;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        n++;
        //graph
        vector< pair<int,int> > adj[n];

        for(int i=0; i<times.size(); i++){

            int start = times[i][0], end = times[i][1], wt = times[i][2];
            adj[start].push_back({end,wt});
        }

        vector<int> dist(n,1e9);
        priority_queue<pp, vector<pp>, greater<pp>> pq;

        pq.push({0, k});
        dist[k] = 0;

        while(!pq.empty()){

            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it: adj[node]){

                int adjNode = it.first;
                int wt = it.second;

                if(d + wt < dist[adjNode]){
                    dist[adjNode] = d + wt;
                    pq.push({d+wt, adjNode});
                }
            }
        }

        int maxtime = -1;
        for(int i=1; i<n; i++){

            if(dist[i] == 1e9){
                return -1;
            }
            else{
                maxtime = max(maxtime, dist[i]);
            }
        }

        return maxtime;
    }
};