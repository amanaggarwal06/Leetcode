class Solution {

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[numCourses];
        vector<int> visited(numCourses, 0);

        for(int i=0; i<prerequisites.size(); i++){
            int pre = prerequisites[i][1];
            int curr = prerequisites[i][0];

            adj[pre].push_back(curr);
        }

        vector<int> indegree(numCourses, 0);

        for(int i=0; i<numCourses; i++){

            for(auto it: adj[i]){
                indegree[it]++;
            }
        }

        queue<int> q;
        vector<int> ans;

        //traverse all the indegree and get the node with 0 indegree
        for(int i=0; i<numCourses; i++){
            
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){

            int node = q.front();
            ans.push_back(node);

            q.pop();

            for(auto it: adj[node]){
                indegree[it]--;

                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        if(ans.size() < numCourses) return false;

        return true;
        
    }
};