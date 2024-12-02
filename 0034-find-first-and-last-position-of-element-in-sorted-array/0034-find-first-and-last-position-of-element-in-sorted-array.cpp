class Solution {
public:
    int binary_first(vector<int> a, int l, int r, int t) {
    
    while(l<=r){
        if(l==r){
            if(a[l] == t) return l;
            else return -1;
        }
        int mid = l + (r - l) / 2;
        if(a[mid]==t ){
            if(mid == l) return mid;
            else if(a[mid-1]!=t) return mid;
            else r = mid-1;
        } 
        else if(a[mid]>=t) r = mid-1;
        else l = mid+1;
    }
        return -1;
    }

    int binary_last(vector<int> a, int l, int r, int t) {
    
    while(l<=r){
        if(l==r){
            if(a[l] == t) return l;
            else return -1;
        }
        int mid = l + (r - l) / 2;
        if(a[mid]==t ){
            if(mid == r) return mid;
            else if(a[mid+1]!=t) return mid;
            else l = mid+1;
        } 
        else if(a[mid]>=t) r = mid-1;
        else l = mid+1;
    }
        return -1;
}


    vector<int> searchRange(vector<int>& nums, int target) {

        return {binary_first(nums,0,nums.size()-1, target),binary_last(nums,0,nums.size()-1, target)};
    }
};