class Solution {
public:
    int helper(int target, vector<int>& c, int index, vector<vector<int>>& dp){
        if(target==0){
            return 1;
        } 
        if(target<0) return 0;
        if(dp[target][index]!=-1){
            return dp[target][index];
        }
        int sum = 0;
        for(int i = index; i < c.size(); i++){
            sum+= helper(target-c[i], c, i,dp);
        }
        return dp[target][index] = sum;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount+1,vector<int>(coins.size(),-1));
        return helper(amount, coins, 0, dp);

    }
};