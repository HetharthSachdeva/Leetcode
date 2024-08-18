class Solution {
public:
    bool check(vector<int>& nums) {
        bool c = false;
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i+1]<nums[i]){
                if(!c) c = !c;
                else return false;
            }
        }
        if(c && nums[0]<nums[nums.size()-1]) return false;
        
        return true;
    }
};