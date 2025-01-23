class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans;
        int m = nums1.size();
        int n = nums2.size();
        for(int i = 0; i < n; i++){
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(), nums1.end());
        
        if((n+m) & 1) ans = nums1[(n+m)/2];
        else ans = (nums1[(n+m)/2]+nums1[(n+m-2)/2])/2.0;
        return ans;
    }
};