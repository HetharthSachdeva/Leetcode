class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return true;
        int ma = 0;
        for(int i = 0; i < n-1; i++){
            if(nums[i]==0 && i==ma) return false;
            if(i+nums[i]>ma) ma = i+nums[i];
        }
        if(ma >= n-1) return true;
        return false;
    }
};