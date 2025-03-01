class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(n));
        for(int i= 0; i < n; i++){
            dp[0][i] = matrix[0][i];
        }
        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){
                dp[i][j] = matrix[i][j] + min(dp[i-1][j], min((j==0?INT_MAX:dp[i-1][j-1]),(j==n-1?INT_MAX:dp[i-1][j+1])));
            }
        }

        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            ans = min(ans, dp[n-1][i]);
        }
        return ans;
    }
};