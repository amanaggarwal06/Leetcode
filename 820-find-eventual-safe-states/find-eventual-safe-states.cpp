class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> adj[n];

        vector<int> indegree(n,0);

        //reversed the edges
        for(int i=0; i<n; i++){
            for(auto it: graph[i]){

                adj[it].push_back(i);
                indegree[i]++;
            }
        }

        //normal topological sort with bfs
        queue<int> q;
        vector<int> ans;

        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){

            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto it: adj[node]){

                indegree[it]--;

                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};