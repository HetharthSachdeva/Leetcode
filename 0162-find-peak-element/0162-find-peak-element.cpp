class Solution {
public:
    int binary(vector<int> k, int i, int j){
        if(i>j) return -1;
        if(i == j){
            if(k[i]>k[i-1] && k[i]>k[i+1]) return i;
            else return -1;
        }
        int mid = i+(j-i)/2;
        if(k[mid] > k[mid+1] && k[mid] > k[mid-1]){
            return mid;
        }
        if(k[mid] > k[mid-1]) return binary(k,mid+1,j);
        else return binary(k,1,mid-1);
        // int e = binary(k, 1, mid-1);
        // if(e > -1) return e;
        // else return binary(k,mid+1, j);
        
    }
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1 || nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;
        return binary(nums, 1, n-2);
    }
};