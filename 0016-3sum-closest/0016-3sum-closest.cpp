class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        long closest = INT_MAX;
        long n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j< n; j++){
                for(int k = j+1; k < n;k++){
                    if(abs(nums[i]+nums[j]+nums[k] - target) < abs(closest-target)) closest = (nums[i]+nums[j]+nums[k]); 
                }
            }
        }
        return closest;
    }
};