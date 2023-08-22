class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> adj[n];
        for(int i=0; i<flights.size(); i++){
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        //priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        queue<pair<int, pair<int, int>>> q;
        vector<int> dist(n, 1e9);
        //pq.push({0, src});
        q.push({0, {src, 0}});
        dist[src] = 0;
        while(!q.empty()){
            int stops = q.front().first;
            int node = q.front().second.first;
            int travelled = q.front().second.second;
            q.pop();
            if(stops > k) continue;
            for(auto it: adj[node]){
                int distance = it[1];
                int neighbour = it[0];
                if(distance + travelled < dist[neighbour]){
                    dist[neighbour] = distance + travelled;
                    //cout<<dist[neighbour]<<" "<<neighbour<<endl;
                    //pq.push({dist[neighbour], neighbour});
                    q.push({stops+1, {neighbour, dist[neighbour]}});
                }
            } 
        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};