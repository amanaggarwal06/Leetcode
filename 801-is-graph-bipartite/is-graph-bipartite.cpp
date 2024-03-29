class Solution {

    bool dfs(int node, int color, vector<pair<int,int>> &visited, vector<int> adj[]){

        visited[node] = {1,color};

        for(auto it:adj[node]){

            if(!visited[it].first){
                if(dfs(it, !color, visited, adj) == false){
                    return false;
                }
            }
            else if(visited[it].second == visited[node].second){
                return false;
            }
        }

        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> adj[n];

        for(int i=0; i<n; i++){
            for(int j=0; j<graph[i].size(); j++){
                adj[i].push_back(graph[i][j]);
            }
        }

        vector<pair<int,int>> visited(n,{0,-1});
        for(int i=0; i<n; i++){

            if(!visited[i].first){
                if(dfs(i,0,visited,adj) == false){
                    return false;
                }
            }
        }

        return true;

    }
};