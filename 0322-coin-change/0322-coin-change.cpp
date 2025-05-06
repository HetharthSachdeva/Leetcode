class Solution {
public:
    int helper(vector<int>& c, int target, vector<int>& dp){
        if(target<0) return INT_MIN;
        if(target==0) return 0;
        if(dp[target]!=-1) return dp[target];
        int k = INT_MAX;
        for(int i: c){
            int j = helper(c, target-i,dp);
            if(j != INT_MIN) k = min(k, j);
        }
        return dp[target] = (k==INT_MAX?INT_MIN:k+1);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        return max(-1,helper(coins, amount, dp));
    }
};