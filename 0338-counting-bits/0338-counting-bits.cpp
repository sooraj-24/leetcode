class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i=0; i<=n; i++){
            int count = 0;
            long long k = i;
            while(k != 0){
                count++;
                k = k&(k-1);
            }
            ans[i] = count;
        }
        return ans;
    }
};