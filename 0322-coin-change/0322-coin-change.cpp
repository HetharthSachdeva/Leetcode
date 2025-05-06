class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for(long i = 0; i < amount+1; i++){
            for(long j : coins){
                if(i+j <=amount && dp[i]!=INT_MAX) dp[i+j] = min(dp[i+j], dp[i]+1);
            }
        }
        return (dp[amount]==INT_MAX?-1:dp[amount]);
    }
};