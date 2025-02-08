class Solution {
public:
    int helper(vector<int>& arr, int i, vector<int>& dp){
        
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i] = max(arr[i]+helper(arr,i-2,dp), helper(arr,i-1, dp));
    }

    int rob(vector<int>& nums) {
        vector<int> d(nums.size(),-1);
        return helper(nums,nums.size()-1, d);
    }
};