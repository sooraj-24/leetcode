class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        int i=0;
        int j=0;
        ans.push_back(matrix[0][0]);
        matrix[0][0] = 101;
        while(true){
            int flag = 0;
            //right
            while(j+1 < n && matrix[i][j+1] != 101){
                j = j+1;
                ans.push_back(matrix[i][j]);
                matrix[i][j] = 101;
                flag = 1;
            }
            //down
            while(i+1 < m && matrix[i+1][j] != 101){
                i = i+1;
                ans.push_back(matrix[i][j]);
                matrix[i][j] = 101;
                flag = 1;
            }
            //left
            while(j-1 >= 0 && matrix[i][j-1] != 101){
                j = j-1;
                ans.push_back(matrix[i][j]);
                matrix[i][j] = 101;
                flag = 1;
            }
            //up
            while(i-1 >= 0 && matrix[i-1][j] != 101){
                i = i-1;
                ans.push_back(matrix[i][j]);
                matrix[i][j] = 101;
                flag = 1;
            }
            if(!flag) break;
        }
        return ans;
    }
};