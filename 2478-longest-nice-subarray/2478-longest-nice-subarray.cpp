class Solution {
public:
    bool check(vector<int>& arr, int len, vector<long long>& sum, vector<long long>& xo){
        for(int i = 0;i <= arr.size()-len; i++){
            if((sum[i+len-1]-sum[i]+arr[i]) == (xo[i+len-1]^xo[i]^arr[i])) return true;
        }
        return false;
    }
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        long long xo=0;
        long long sum = 0;
        vector<long long> s(n), x(n);
        for(int i = 0; i < n; i++){
            sum+=nums[i];
            xo^=nums[i];
            s[i] = sum;
            x[i] = xo;
        }
        int i = 1, j = min(n, 30);
        int ans = 1;
        while(i <= j){
            int mid = i+(j-i)/2;
            if(check(nums, mid, s, x)){
                i=mid+1;
                ans = mid;
            } 
            else j = mid-1;
        }
        return ans;
    }
};