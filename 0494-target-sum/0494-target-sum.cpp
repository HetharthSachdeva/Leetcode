class Solution {
public:
    int helper(vector<int>& arr, int t, int index){
        if(index==arr.size()){
            if(t==0) return 1;
            else return 0;
        }
        return helper(arr, t-arr[index], index+1)+helper(arr, t+arr[index], index+1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n= nums.size();
        return helper(nums, target, 0);
    }
};