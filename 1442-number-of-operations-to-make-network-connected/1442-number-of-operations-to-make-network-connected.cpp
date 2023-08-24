class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }
    int findParent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }
    void unionBySize(int u, int v){
        int U = findParent(u);
        int V = findParent(v);
        if(U == V) return;
        if(size[U] < size[V]){
            parent[U] = V;
            size[V] += size[U]; 
        } else {
            parent[V] = U;
            size[U] += size[V];
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extras = 0;
        for(int i=0; i<connections.size(); i++){
            if(ds.findParent(connections[i][0]) == ds.findParent(connections[i][1])){
                extras++;
            } else {
                ds.unionBySize(connections[i][0], connections[i][1]);
            }
        }
        int components = 0;
        for(int i=0; i<n; i++){
            if(ds.parent[i] == i) components++;
        }
        if(extras >= components-1){
            return components-1;
        } else {
            return -1;
        }
        return 0;
    }
};