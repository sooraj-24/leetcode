class DisjointSet {
    vector<int> rank, parent;
public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }
    int findUPar(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionByRank(int u, int v){
        int parentU = findUPar(u);
        int parentV = findUPar(v);
        if(parentU == parentV) return;
        if(rank[parentU] > rank[parentV]){
            parent[parentV] = parentU;
        } else if(rank[parentU] < rank[parentV]){
            parent[parentU] = parentV;
        } else {
            parent[parentV] = parentU;
            rank[parentU]++;
        }
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSet ds(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j]){
                    ds.unionByRank(i, j);
                }
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            if(ds.findUPar(i) == i) ans++;
        }
        return ans;
    }
};