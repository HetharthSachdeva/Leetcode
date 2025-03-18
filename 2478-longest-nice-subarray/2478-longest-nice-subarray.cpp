class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0, orr = 0, ans = 1;
        while(j < n){
            if((orr&nums[j]) != 0 && i < j){
                orr^=(nums[i++]);
                
            }
            else{
                orr|=nums[j];
                ans = max(ans, j-i+1);
                j++;
            }
        }
        return ans;
    }
};