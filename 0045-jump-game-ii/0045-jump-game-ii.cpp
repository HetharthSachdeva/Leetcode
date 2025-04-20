class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        int ma = 0, count = 0, ma2 = 0;
        for(int i = 0; i < n-1; i++){
            if(i+nums[i] > ma2) ma2 = i+nums[i];
            if(i==ma){
                ma = ma2;
                count++;
            }
        }
        return count;
    }
};