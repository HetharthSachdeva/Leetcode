class Solution {
public:
    bool helper(vector<int>& a, long long k, int ind, long long mysum){
        if(mysum == k/2){
            return true;
        }
        if(ind >= a.size()) return false;
        bool take = helper(a, k, ind+1, mysum+a[ind]);
        bool nottake = helper(a, k, ind+1, mysum);

        return take||nottake;

    }
    bool canPartition(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        long long sum = 0;
        for(int i : nums) sum+= i;
        if(sum&1) return false;

        // return helper(nums, sum, 0, 0);
        int n = nums.size();
        vector<vector<bool>> dp(n, vector<bool>(sum/2 + 1, false));

        for(int i = 0; i < n; i++){
            dp[i][0] = true;
        }
        if(nums[0] <= sum/2) dp[0][nums[0]] = true;

        for(int i = 1; i < n; i++){
            for(int j = 1; j <= sum/2; j++){
                dp[i][j] = dp[i-1][j] || ((nums[i]<=j)?dp[i-1][j-nums[i]]:false);
            }
        }
        return dp[n-1][sum/2];
    }
};