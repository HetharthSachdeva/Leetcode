class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<long>> dp(n+1, vector<long>(m+1, 0));
        for(int i = 0; i <n; i++){
             dp[i][0] = 1;
        }
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(t[i-1]==s[j-1]){
                    dp[j][i] = (dp[j-1][i]+dp[j-1][i-1]) % INT_MAX;
                } 
                else dp[j][i] = dp[j-1][i];
            }
        }
        return dp[n][m];

    }
};