class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n + 1, -1);
        return rec(n-1, s, wordDict, dp);
    }
    bool rec(int ind, string s, vector<string>& wordDict, vector<int>& dp){
        if(ind < 0) return dp[ind + 1] = true;
        if(dp[ind + 1] != -1) return dp[ind + 1];
        for(int i=0; i<wordDict.size(); i++){
            int n = wordDict[i].length();
            if(ind - n + 1 >= 0){
                if(s.substr(ind-n+1, n) == wordDict[i]){
                    if(rec(ind - n, s, wordDict, dp)) return dp[ind + 1] = true;
                }
            }
        }
        return dp[ind + 1] = false;
    }
};