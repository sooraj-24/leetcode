class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<int> delrow = {-1, 0, 1, 0};
        vector<int> delcol = {0, -1, 0, 1};
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]){
                    for(int k=0; k<4; k++){
                        int nrow = i + delrow[k];
                        int ncol = j + delcol[k];
                        if(nrow<0 || nrow>=m || ncol<0 || ncol>=n || !grid[nrow][ncol]){
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};