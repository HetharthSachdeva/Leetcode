class Solution {
public:
    int solve(vector<int>& arr, int ind, int prev, vector<vector<int>>& dp){
        if(ind>=arr.size()){
            return 0;
        }

        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];

        int no = solve(arr, ind+1, prev, dp);
        int take = 0;
        if(prev==-1 || arr[prev]<arr[ind]) take = 1 + solve(arr, ind+1, ind, dp);

        return dp[ind][prev+1] = max(no, take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1,-1));
        return solve(nums, 0, -1, dp);       
    }    
};