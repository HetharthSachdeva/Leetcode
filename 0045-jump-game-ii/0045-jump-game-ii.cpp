class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        if(n==1) return 0;
        dp[0] = 0, dp[1] = (nums[0]==0?INT_MAX:1);
        for(int i = 0; i < n; i++){
            for(int j = 1; j <= nums[i] && i+j < n;j++){
                dp[i+j] = min(dp[i]+1, dp[i+j]);
            }
        }
        return dp[n-1];
    }
};