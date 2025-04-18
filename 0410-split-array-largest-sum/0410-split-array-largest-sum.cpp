class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int i = *max_element(nums.begin(),nums.end()), j = accumulate(nums.begin(),nums.end(), 0);
        int n = nums.size();
        while(i < j){
            int mid = i+(j-i)/2;
            int subs = 0;
            int sum = 0;
            for(int i : nums){
                if(sum+i > mid){
                    subs++;
                    sum = i;
                }
                else sum+=i;
            }
            if(sum > 0) subs++;

            if(subs <= k) j = mid;
            else i = mid+1;
        }
        return i;
    }
};