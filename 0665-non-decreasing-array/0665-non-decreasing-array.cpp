class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return true;
        int ans = 0;
        int k = 0;
        for(int i = 1;  i < n; i++){
            if(nums[i] < nums[i-1]){
                ans++;
                k = i;
            }
        }
        if(ans >= 2) return false;
        if(ans == 0) return true;
        if(k==n-1 || k==1) return true;
        if(nums[k-1] <= nums[k+1] ) return true;
        if(nums[k-2] <= nums[k]) return true;
        return false;
    }
};