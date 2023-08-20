class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] || grid[n-1][n-1]) return -1;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        pq.push({1, {0,0}});
        dist[0][0] = 1;
        vector<int> delrow = {0,1,1,1,0,-1,-1,-1};
        vector<int> delcol = {-1,-1,0,1,1,1,0,-1};
        while(!pq.empty()){
            int travelled = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            for(int i=0; i<8; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && !grid[nrow][ncol]){
                    if(travelled + 1 < dist[nrow][ncol]){
                        dist[nrow][ncol] = travelled + 1;
                        pq.push({travelled+1, {nrow, ncol}});
                    }
                }
            }
        }
        if(dist[n-1][n-1] == 1e9) return -1;
        else return dist[n-1][n-1];
    }
};