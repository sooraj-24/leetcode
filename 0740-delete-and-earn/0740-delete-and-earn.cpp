class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> count;
        vector<int> arr;
        for(int i=0; i<nums.size(); i++){
            if(count.find(nums[i]) == count.end()){
                arr.push_back(nums[i]);
            }
            count[nums[i]]++;
        }
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<int> dp(n+1, 0);
        dp[1] = arr[0]*count[arr[0]];
        for(int i=2; i<=n; i++){
            int take = -1e9;
            if(arr[i-2] == arr[i-1] - 1){
                take = arr[i-1]*count[arr[i-1]] + dp[i-2];
            } else {
                take = arr[i-1]*count[arr[i-1]] + dp[i-1];
            }
            int notTake = dp[i-1];
            dp[i] = max(take, notTake);
        }
        return dp[n];
    }
    int rec(int i, vector<int> arr, unordered_map<int, int> count, vector<int>& dp){
        if(i == 0){
            return dp[i] = arr[0]*count[arr[0]];
        }
        if(i < 0) {
            return 0;
        }
        if(dp[i] != -1) return dp[i];
        //take
        int take = -1e9;
        if(arr[i-1] == arr[i] - 1){
            take = arr[i]*count[arr[i]] + rec(i-2, arr, count, dp);
        } else {
            take = arr[i]*count[arr[i]] + rec(i-1, arr, count, dp);
        }
        //notTake
        int notTake = rec(i-1, arr, count, dp);

        return dp[i] = max(take, notTake);
    }
};