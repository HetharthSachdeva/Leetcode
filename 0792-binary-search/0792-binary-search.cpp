class Solution {
public:
    int search(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int i = 0, j = nums.size()-1;
        while(i<=j){
            if(i==j){
                if(nums[i]==target) return i;
                else return -1;
            }
            int mid = i+ (j-i)/2;
            if(target < nums[mid]) j = mid-1;
            else if(target > nums[mid]) i = mid+1;
            else return mid;
        }
        return -1;
    }
};