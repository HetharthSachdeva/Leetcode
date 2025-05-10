class Solution {
public:
    int helper(vector<int>& arr, int t, int index, vector<vector<int>>& d){

        if(index==arr.size()){
            if(t==0) return 1;
            else return 0;
        }
        if(d[t+2001][index]!=-1) return d[t+2001][index];
        return d[t+2001][index] = helper(arr, t-arr[index], index+1, d)+helper(arr, t+arr[index], index+1, d);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n= nums.size();
        vector<vector<int>> dp(2*2000+1, vector<int>(nums.size(),-1));
        return helper(nums, target, 0, dp);
    }
};