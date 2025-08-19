class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        vector<int> j; int l = 0;
        for(int i = 0; i < n; i++){
            if(nums[i]==0) l++;
            else if(l>0){
                j.push_back(l);
                l=0;
            } 
            else l = 0;
        }
        if(l>0) j.push_back(l);

        for(long long i: j){
            ans += (i*(i+1))/2;
        }
        return ans;
    }
};