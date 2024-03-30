class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[n];
        vector<int> visited(n,0);

        for(int i=0; i<prerequisites.size(); i++){
            int first = prerequisites[i][1];
            int second = prerequisites[i][0];

            adj[first].push_back(second);
        }

        vector<int> indegree(n,0);

        for(int i=0; i<n; i++){

            for(auto it: adj[i]){
                indegree[it]++;
            }
        }

        queue<int> q;

        //put all nodes with 0indegree

        for(int i=0; i<n; i++){

            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty()){

            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto it: adj[node]){

                if(!visited[it]){

                    indegree[it]--;
                    if(indegree[it] == 0){
                        q.push(it);
                        visited[it] = 1;
                    }
                }
            }
        }

        vector<int> temp;
        if(ans.size() < n){
            return temp;

        }

        return ans;
        
    }
};