class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (n*(n+1)) / 2;
        for(int k = 0; k < n; k++) sum-=nums[k];
        return sum;
    }
};