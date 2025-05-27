class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n= nums.size();
        int sum = 0;
        for(int i:nums) sum+= i;
        if(target > sum ) return 0;
        if((sum-target) & 1) return 0;
        vector<vector<int>> dp((sum-target)/2 + 1,vector<int>(n,0));
        // for(int i = 0; i < n; i++){
        //     dp[0][i]=1;
        // }
        dp[0][0] = 1;

        if(nums[0] <= (sum-target)/2) dp[nums[0]][0] += 1;
        for(int i = 1; i < n; i++){
            for(int j = 0; j <= (sum-target)/2; j++){
                dp[j][i]+=dp[j][i-1];
                if(j-nums[i]>=0) dp[j][i] += dp[j-nums[i]][i-1];
            }
        }

        return dp[(sum-target)/2][n-1];
    }
};