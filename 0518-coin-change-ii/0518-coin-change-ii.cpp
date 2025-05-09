class Solution {
public:
    int change(int amount, vector<int>& coins) {
       vector<int> dp(amount+1, 0);
       dp[0] = 1;
       for(int c: coins){
            for(int i = c; i < amount+1; i++){
                if(dp[i] < INT_MAX-dp[i-c]) dp[i]= (dp[i]+dp[i-c]);
                else dp[i] += (INT_MIN+dp[i-c]);
            }
       }
       return dp[amount];
    }
};