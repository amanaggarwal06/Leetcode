
class disjointSet{

public:
    vector<int> parent;
    vector<int> size;
    disjointSet(int n){
        parent.resize(n);
        size.resize(n,1);
    }

    int findParent(int node){

        if(node == parent[node]) return node;

        return parent[node] = findParent(parent[node]);
    }

    void UnionBySize(int u, int v){

        int ult_p_u = findParent(u), ult_p_v = findParent(v);

        if(size[ult_p_u] < size[ult_p_v]){
            parent[ult_p_u] = ult_p_v;
            size[ult_p_v] += size[ult_p_u];
        }
        else{
            parent[ult_p_v] = ult_p_u;
            size[ult_p_u] += size[ult_p_v];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int extra_cnt = 0, numOfProvinces = 0;
        disjointSet ds(n);

        for(int i=0; i<n; i++){
            ds.parent[i] = i;
        }

        for(auto it: connections){
            int u = it[0], v = it[1];

            if(ds.findParent(u) == ds.findParent(v)){
                extra_cnt++;
            }
            else{
                ds.UnionBySize(u,v);
            }
        }

        for(int i=0; i<n; i++){
            if(ds.parent[i] == i) numOfProvinces++;
        }

        int ans = numOfProvinces - 1;

        if(extra_cnt >= ans) return ans;
        return -1;



    }
};