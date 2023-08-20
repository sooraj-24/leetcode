class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        pq.push({0, {0, 0}});
        dist[0][0] = 0;
        vector<int> delrow = {-1, 0, 1, 0};
        vector<int> delcol = {0, -1, 0, 1};
        while(!pq.empty()){
            int travelled = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            for(int i=0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    if(max(dist[row][col], abs(grid[nrow][ncol] - grid[row][col])) 
                    < dist[nrow][ncol]){
                        dist[nrow][ncol]= max(dist[row][col], abs(grid[nrow][ncol] - grid[row][col]));
                        pq.push({dist[nrow][ncol], {nrow, ncol}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};