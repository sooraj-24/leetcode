class Solution {
public:
    void dfs(int r, int c, int color, int ini, vector<vector<int>>& vis,  vector<vector<int>>& image){
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        if(image[sr][sc] != color){
            int startColor = image[sr][sc];
            q.push({sr, sc});
            vis[sr][sc] = 1;
            image[sr][sc] = color;
            while(!q.empty()){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                if(r-1 >=0 && r-1<m && image[r-1][c] == startColor && vis[r-1][c] == 0){
                    vis[r-1][c] = 1;
                    q.push({r-1, c});
                    image[r-1][c] = color;
                }
                if(r+1 >=0 && r+1<m && image[r+1][c] == startColor && vis[r+1][c] == 0){
                    vis[r+1][c] = 1;
                    q.push({r+1, c});
                    image[r+1][c] = color;
                }
                if(c+1 >=0 && c+1<n && image[r][c+1] == startColor && vis[r][c+1] == 0){
                    vis[r][c+1] = 1;
                    q.push({r, c+1});
                    image[r][c+1] = color;
                }
                if(c-1 >=0 && c-1<n && image[r][c-1] == startColor && vis[r][c-1] == 0){
                    vis[r][c-1] = 1;
                    q.push({r, c-1});
                    image[r][c-1] = color;
                }
            }
        }
        return image;
    }
};