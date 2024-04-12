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
    int removeStones(vector<vector<int>>& stones) {
        
        //connect all the nodes acc to the constraint
        int n = stones.size();
        int maxrow = 0, maxcol = 0;

        for(auto it: stones){
            maxrow = max(maxrow, it[0]);
            maxcol = max(maxcol, it[1]);
        }

        disjointset ds(maxrow + maxcol + 1);
        unordered_map<int, int> mp;

        for(auto it: stones){

            int r = it[0], c = it[1] + (maxrow + 1);

            mp[r] = 1;
            mp[c] = 1;
            ds.unionbysize(r,c);
        }

        int provinces = 0;

        // for(auto it: stones){

        //     int r = it[0], c = it[1];

        //     if(r == ds.findParent(r)) provinces++;
        //     if(c == ds.findParent(c)) provinces++;
        // }

        for(auto it: mp){

            if(it.first == ds.findParent(it.first)){
                provinces++;
            }
        }

        return (n - provinces);
    }
};