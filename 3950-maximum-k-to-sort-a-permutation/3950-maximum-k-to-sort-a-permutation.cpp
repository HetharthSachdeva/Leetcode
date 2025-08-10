class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        long ans= pow(2,32)-1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]!=i) ans &= nums[i];
        }
        return (ans>INT_MAX?0:ans);
    }
};