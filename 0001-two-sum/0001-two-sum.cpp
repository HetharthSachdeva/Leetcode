class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size()-1; i++ ){
            for(int j = nums.size()-1; j>i; j-- ){
                if(target == nums[i]+ nums[j]){
                    return {i,j};
                }
            }
        }
       return {};
    }
};