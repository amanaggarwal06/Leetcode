class Solution {

    void dfs(int node, int parent, vector<int> adj[] ,vector<int> &in_time, vector<int> &lowest_time, vector<int> &vis, vector<vector<int>> &ans, int &timer){

        timer++;
        in_time[node] = lowest_time[node] = timer;
        vis[node] = 1;

        for(auto it: adj[node]){

            if(it == parent) continue;
            if(vis[it] == 0){
                dfs(it, node, adj, in_time, lowest_time, vis, ans, timer);

                //check for bridge
                lowest_time[node] = min(lowest_time[node], lowest_time[it]);

                if(lowest_time[it] > in_time[node]){
                    ans.push_back({node, it});
                }
            }
            else{

                lowest_time[node] = min(lowest_time[node], lowest_time[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>> ans;
        vector<int> insertion_time(n,0);
        vector<int> lowest_in_time(n,0);
        int timer = 0;

        vector<int> vis(n,0);

        vector<int> adj[n];
        for(auto it: connections){

            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        dfs(0,-1, adj, insertion_time, lowest_in_time, vis, ans, timer);
        return ans;
    }
};