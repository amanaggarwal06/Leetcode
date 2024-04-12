class disjointset{

public:
    vector<int> parent;
    vector<int> size;

    disjointset(int n){
        parent.resize(n+1, 0);
        size.resize(n+1, 0);

        for(int i=0; i<=n;i++){
            parent[i] = i;
        }
    }

    int findParent(int node){

        //base condition
        if(node == parent[node]) return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionbysize(int u, int v){

        int ult_p_u = findParent(u), ult_p_v = findParent(v);

        if(ult_p_u != ult_p_v){

            if(size[ult_p_u] > size[ult_p_v]){
                parent[ult_p_v] = parent[ult_p_u];
                size[ult_p_u] += size[ult_p_v];
            }
            else{
                 parent[ult_p_u] = parent[ult_p_v];
                size[ult_p_v] += size[ult_p_u];
            }
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        int n =accounts.size();
        disjointset ds(n);
        unordered_map<string, int> mp;

        for(int i=0; i<n; i++){
            for(int j = 1; j< accounts[i].size(); j++){
                
                string mail = accounts[i][j];
                int node = i;

                if(mp.find(mail) == mp.end()){
                    mp[mail] = i;
                }
                else{
                    ds.unionbysize(i, mp[mail]);
                }
            }
        }

        vector<vector<string>> mailNodes(n);

        for(auto it: mp){

            string mail = it.first;
            int node = ds.findParent(it.second);
            mailNodes[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for(int i=0; i<n; i++){

            if(mailNodes[i].size() == 0) continue;
            sort(mailNodes[i].begin(), mailNodes[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);
            temp.insert(temp.end(), mailNodes[i].begin(), mailNodes[i].end());
            ans.push_back(temp);
        }

        return ans;

    }
};