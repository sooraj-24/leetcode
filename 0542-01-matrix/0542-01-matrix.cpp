class Solution {
public:
    void calculate(queue<pair<pair<int,int>, int>>& q, vector<vector<int>>& vis, vector<vector<int>>& mat){
        int m = mat.size();
        int n = mat[0].size();
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            mat[row][col] = dist;
            if(row-1>=0 && vis[row-1][col] == 0){
                q.push({{row-1, col}, dist+1});
                vis[row-1][col] = 1;
            }
            if(row+1<m && vis[row+1][col] == 0){
                q.push({{row+1, col}, dist+1});
                vis[row+1][col] = 1;
            }
            if(col-1>=0 && vis[row][col-1] == 0){
                q.push({{row, col-1}, dist+1});
                vis[row][col-1] = 1;
            }
            if(col+1<n && vis[row][col+1] == 0){
                q.push({{row, col+1}, dist+1});
                vis[row][col+1] = 1;
            }  
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<pair<int,int>, int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0){
                    q.push({{i,j}, 0});
                    vis[i][j] = 1;
                }
            }
        }
        calculate(q, vis, mat);
        return mat;
    }
};