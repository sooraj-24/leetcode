class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(int i=0; i<n; i++){
            total += nums[i];
        }
        if(total % 2 != 0) return false;
        int target = total/2;
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        // for(int i=0; i<n; i++){
        //     dp[i][0] = true;
        // }
        // if(nums[0] <= target) dp[0][nums[0]] = true;
        // for(int i=1; i<n; i++){
        //     for(int j=1; j<=target; j++){
        //         bool notTaken = dp[i-1][j];
        //         bool taken = false;
        //         if(nums[i] <= j) taken = dp[i-1][j-nums[i]];
        //         dp[i][j]= notTaken||taken;
        //     }
        // }
        //return dp[n-1][target];
        return rec(n-1, target, nums, dp);
    }
    bool rec(int i, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(target == 0) return dp[i][target] = true;
        if(i == 0) return nums[i] == target;
        if(dp[i][target] != -1) return dp[i][target];
        bool notTake = rec(i-1, target, nums, dp);
        bool take = false;
        if(target >= nums[i]){
            take = rec(i-1, target - nums[i], nums, dp);
        }
        return dp[i][target] = notTake || take;
    }
};