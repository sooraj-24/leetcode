class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& isConnected){
        vis[node] = 1;
        for(int i=0; i<isConnected.size(); i++){
            if(isConnected[node-1][i] && !vis[i+1]){
                dfs(i+1, vis, isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n+1, 0);
        int ans = 0;
        for(int i=1; i<=n; i++){
            if(vis[i] == 0){
                ans++;
                dfs(i, vis, isConnected);
            }
        }
        return ans;
    }
};