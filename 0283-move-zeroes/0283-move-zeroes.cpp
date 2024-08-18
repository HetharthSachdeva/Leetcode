class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        // int i = 0, j = 0;
        for(int i = 0; i < n; i++){
            if(nums[i]==0){
                for(int j = i+1; j < n; j++){
                    if(nums[j]!=0){
                        swap(nums[i],nums[j]);
                        break;
                    }
                }
            }
        }
    }
};