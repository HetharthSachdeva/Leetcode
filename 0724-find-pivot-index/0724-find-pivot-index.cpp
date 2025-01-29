class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        long sum = 0;
        for(int i : nums) sum+=i;
        int n= nums.size();
        long l = 0;
        for(int i = 0; i < n; i++){
            if(l== sum-l-nums[i]) return i;
            l+=nums[i];
        }
        return -1;
    }
};