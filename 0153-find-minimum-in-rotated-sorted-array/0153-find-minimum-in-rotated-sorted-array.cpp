class Solution {
public:
    int findMin(vector<int>& nums) {
            int n = nums.size();
            if(nums[n-1] > nums[0]) return nums[0];
            int l = 1, r = n-1;
            while(true){
                if(l==r) return nums[l];
                if(l>r) return nums[r];
                if(nums[l] < nums[r]) return nums[l];
                int mid = l + (r-l)/2;
                if(nums[mid] < nums[mid-1]) return nums[mid];
                if(nums[mid]>=nums[l]) l = mid+1;
                else r = mid-1;
            }
    }
};