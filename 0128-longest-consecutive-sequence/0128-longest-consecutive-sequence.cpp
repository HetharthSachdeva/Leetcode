class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        if(nums.size() == 0) return 0;
        sort(nums.begin(),nums.end());
        int curr = 1;
        int max = 1;
        int n = nums.size();
        for(int i = 0; i < n-1; i++){
            if(nums[i] == nums[i+1]-1){
                curr++;
                if(max<curr) max = curr;
            }
            else if(nums[i]==nums[i+1]) continue;
            else{
                curr = 1;
            }
        }
        return max;
    }
};