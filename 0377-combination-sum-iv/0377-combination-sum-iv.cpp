class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for(int i=1; i<=target; i++){
            long long val = 0;
            for(int j=0; j<nums.size(); j++){
                if(i >= nums[j]){
                    val += dp[i - nums[j]];
                }
            }
            dp[i] = val;
        }
        return dp[target];
    }
    // int rec(int target, vector<int> nums, vector<int>& dp){
    //     if(target == 0) return dp[0] = 1;
    //     if(dp[target] != -1) return dp[target];
    //     int val = 0;
    //     for(int i=0; i<nums.size(); i++){
    //         if(target >= nums[i]){
    //             val += rec(target - nums[i], nums, dp);
    //         }
    //     }
    //     return dp[target] = val;
    // }
};