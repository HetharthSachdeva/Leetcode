class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int l = 0, r = nums.size()-1;
        while(l<=r){
            if(l==r) return nums[l];
            int mid = l + (r-l)/2;
            if(nums[mid] == nums[mid+1] && mid%2 == 0) l = mid+2;
            else if(nums[mid] == nums[mid-1] && mid%2 == 0) r = mid-2;
            else if(nums[mid] == nums[mid+1] && mid%2 != 0) r = mid-1;
            else if(nums[mid] == nums[mid-1] && mid%2 != 0) l = mid+1;
            else return nums[mid];
        }
        return nums[0];
        // [3,3,7,7,10,11,11]
    }
};