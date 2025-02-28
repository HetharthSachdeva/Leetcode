class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int m = o.size();
        int n = o[0].size();

        vector<vector<int>> dp(m, vector<int>(n,0));

        dp[0][0] = 1;
        for(int i = 1; i < m; i++){
            if(o[i][0]==1) dp[i][0] = 0;
            else dp[i][0] = dp[i-1][0];
        }
        for(int i = 1; i < n; i++){
            if(o[0][i]==1) dp[0][i] = 0;
            else dp[0][i] = dp[0][i-1];
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = (!o[i-1][j]?dp[i-1][j]:0)+(!o[i][j-1]?dp[i][j-1]:0);
            }
        }
        return ((o[m-1][n-1] || o[0][0]) ?0:dp[m-1][n-1]);

    }
};