class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                }
            }
        }
        int ans = 0;
        vector<int> delrow = {-1, 0, 1, 0};
        vector<int> delcol = {0, -1, 0, 1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            if(vis[row][col]) continue;
            vis[row][col] = 1;
            for(int i=0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                //cout<<nrow<<ncol<<endl;
                if(nrow>=m || nrow<0 || ncol>=n || ncol<0 || grid[nrow][ncol] == 0){
                    ans++;
                    cout<<row<<col<<" "<<nrow<<ncol<<endl;
                }
                if(nrow<m && nrow>0 && ncol<n && ncol>0 && 
                !vis[nrow][ncol] && grid[nrow][ncol]){
                    q.push({nrow, ncol});
                    //cout<<row<<col<<endl;
                }
            }
        }
        return ans;
    }
};