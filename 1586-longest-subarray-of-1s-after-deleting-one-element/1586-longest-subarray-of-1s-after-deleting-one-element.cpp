class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n= nums.size(), i = 0, j = 0;
        bool zero = true;
        int ans = 0, len = 0; 
        while(j < n){
            if(nums[j] == 0){
                if(zero){
                    j++;
                    zero = false;
                } 
                else{
                    while(nums[i]!=0) i++;
                    i++;
                    zero = true;
                    len = j-i;
                }
            }
            else{
                len++;
                ans= max(ans, len);
                j++;
            }
        }
        if(ans == n) return ans-1;
        return ans;
    }
};