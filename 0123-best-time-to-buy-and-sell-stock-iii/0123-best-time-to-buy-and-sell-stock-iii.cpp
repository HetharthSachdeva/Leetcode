class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n, 0), dp2(n, 0);
        dp[0] = 0; int min = prices[0];
        for(int i = 1; i < n; i++){
            if(prices[i]-min > 0 && prices[i]-min > dp[i-1]) dp[i] = prices[i]-min;
            else if(prices[i] < min){
                min = prices[i];
                dp[i] = dp[i-1];
            } 
            else dp[i] = dp[i-1];
        }

        dp2[n-1] = 0; int ma = prices[n-1];
        for(int i = n-2; i >= 0; i--){
            if(ma - prices[i] > 0 && ma - prices[i] > dp2[i+1]) dp2[i] = ma - prices[i];
            else if(prices[i] > ma){
                ma = prices[i];
                dp2[i] = dp2[i+1];
            } 
            else dp2[i] = dp2[i+1];
        }

        int ans = dp[0]+dp2[0];
        for(int i = 1; i < n; i++){
            ans = max(ans, dp[i]+dp2[i]);
        }

        return ans;





    }
};