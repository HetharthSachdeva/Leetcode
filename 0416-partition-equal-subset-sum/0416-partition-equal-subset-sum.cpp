class Solution {
public:
    bool canPartition(vector<int>& nums) {
        long long sum = 0;
        for(int i : nums) sum+= i;
        if(sum&1) return false;
        int n = nums.size();

        // vector<vector<bool>> dp(n, vector<bool>(sum/2 + 1, false));
        vector<bool> prev(sum/2 + 1, false), curr(sum/2 + 1, false);
        prev[0] = true;
        if(nums[0] <= sum/2) prev[nums[0]] = true;

        for(int i = 1; i < n; i++){
            for(int j = 1; j <= sum/2; j++){
                curr[j] = prev[j] || ((nums[i]<=j)?prev[j-nums[i]]:false);
            }
            prev = curr;
        }
        return prev[sum/2];
    }
};