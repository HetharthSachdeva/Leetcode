class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<bool> what(n, false); 
        for(int i = 0; i < n; i++){
            if(nums[i]<=n && nums[i]>=1){
                what[nums[i]-1] = true;
            }
        }
        for(int i = 0; i < n; i++){
            if(!what[i]) return i+1;
        }
        return n+1;
    }
};