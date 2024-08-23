class Solution {
public:
    int majorityElement(vector<int>& nums) {
        ios_base::sync_with_stdio(false);

        int count = 0;
        int ele = nums[0];
        for(int i: nums){
            if(count==0){
                ele = i;
                count++;
            }
            else if(ele==i) count++;
            else if(ele!=i){
                count--;
            }
        }
        return ele;
    }
};