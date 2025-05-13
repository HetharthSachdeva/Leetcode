class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if(sum&1) return false;
        sum /= 2;
        vector<vector<int>> dp(sum+1, vector<int>(n, false));
        for(int i = 0; i < n; i++){
            dp[0][i] = true;
        }
        if(nums[0]<sum+1) dp[nums[0]][0] = true; 
        for(int i = 0; i < sum+1; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = dp[i][j-1] || (nums[j] > i? false: dp[i-nums[j]][j-1]);
            }
        }
        return dp[sum][n-1];
    }
};