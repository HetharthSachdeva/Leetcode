class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int x = 0;
        int n = nums.size();
        if(n < 3) return nums[0];
        for(int i = 0; i < n-1; i++){
            if(nums[i] != nums[i+1] ){
                if(i-x+1 > n/2) return nums[i];
                else x = i;
            }
            else if(i == n - 2 && i-x+1 > n/2) return nums[i];
        }
        return x;
    }
};