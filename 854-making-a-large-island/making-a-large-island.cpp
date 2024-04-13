
class disjointset{

public:
    vector<int> parent;
    vector<int> size;

    disjointset(int n){
        parent.resize(n);
        size.resize(n, 1);

        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }

    int findParent(int node){

        if(node == parent[node]){
            return node;
        }

        return parent[node] = findParent(parent[node]);
    }

    void unionbysize(int u, int v){

        int ult_p_u = findParent(u), ult_p_v = findParent(v);

        if(ult_p_u != ult_p_v){

            if(size[ult_p_u] < size[ult_p_v]){
                parent[ult_p_u] = ult_p_v;
                size[ult_p_v] += size[ult_p_u];
            }
            else{
                parent[ult_p_v] = ult_p_u;
                size[ult_p_u] += size[ult_p_v];
            }
        }
        return;
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        disjointset ds(n*n);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){

                if(grid[i][j] == 0) continue;

                int del_row[] = {-1,0,1,0};
                int del_col[] = {0,1,0,-1};

                for(int k = 0; k<4; k++){
                    int nrow = i + del_row[k];
                    int ncol = j + del_col[k];

                    if(nrow>=0 && nrow < n && ncol>=0 && ncol<n && grid[nrow][ncol] == 1){
                        ds.unionbysize(i*n + j, nrow*n + ncol);
                    }
                }
            }
        }

        int maxi = 0; bool flag = false;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int cnt = 0;

                if(grid[i][j] == 1) continue;

                flag = true;
                set<int> st;
                int del_row[] = {-1,0,1,0};
                int del_col[] = {0,1,0,-1};

                for(int k = 0; k<4; k++){
                    int nrow = i + del_row[k];
                    int ncol = j + del_col[k];

                    if(nrow>=0 && nrow < n && ncol>=0 && ncol<n && grid[nrow][ncol] == 1){
                        st.insert(ds.findParent(nrow*n + ncol));
                    }
                }

                for(auto it: st){
                    cnt += ds.size[it];
                }

                cnt++;
                maxi = max(maxi, cnt);
            }
        }

        if(flag == false){
            return n*n;
        }

        return maxi;
    }
};