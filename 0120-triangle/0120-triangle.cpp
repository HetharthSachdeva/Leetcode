class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n);
        dp[0].push_back(triangle[0][0]);
        for(int i = 1; i < n; i++){
            dp[i].push_back(triangle[i][0] + dp[i-1][0]);
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j < triangle[i].size(); j++){
                dp[i].push_back(min(dp[i-1][j-1],((j==i)?INT_MAX:dp[i-1][j])) + triangle[i][j]);
            }
        }

        int mi = INT_MAX;
        for(int i = 0; i < n; i++){
            if(mi > dp[n-1][i]) mi = dp[n-1][i];
        }

        return mi;
    }
};