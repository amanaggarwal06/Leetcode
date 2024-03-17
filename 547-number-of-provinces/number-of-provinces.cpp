class Solution {

    void dfs(int node, vector<int> &visited, vector<int> adj[]){

        //dfs will work here
        visited[node] = 1;
        for(auto it: adj[node]){

            if(!visited[it]){
                dfs(it, visited, adj);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int cnt = 0; int n = isConnected.size();
        vector<int> visited(n+1, 0);
        vector<int> adj[n];

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){

                if(isConnected[i][j] == 1 && i!=j){
                    adj[i].push_back(j);
                    // adj[j].push_back(i);
                } 
            }
        }



        for(int i=0; i<n; i++){

            if(!visited[i]){
                cnt++;
                dfs(i, visited, adj);
            }
        }

        return cnt;
    }
};