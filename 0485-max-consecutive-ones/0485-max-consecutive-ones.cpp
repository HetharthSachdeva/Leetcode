class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0;
        int count = 0;
        for(int i : nums){
            if(i) count++;
            else{
                max = count>max? count:max;
                count = 0;
            }
        }
        max = count>max? count:max;
        return max;

    }
};