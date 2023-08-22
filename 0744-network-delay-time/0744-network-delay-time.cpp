class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> adj[n+1];
        for(int i=0; i<times.size(); i++){
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n+1, 1e9);
        pq.push({0, k});
        dist[k] = 0;
        while(!pq.empty()){
            int travelled = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it: adj[node]){
                int time = it[1];
                int adjNode = it[0];
                if(travelled + time < dist[adjNode]){
                    dist[adjNode] = travelled + time;
                    pq.push({travelled + time, adjNode});
                }
            }
        }
        int ans = 0;
        for(int i=1; i<=n; i++){
            if(dist[i] == 1e9) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};