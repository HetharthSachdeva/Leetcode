class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = nums.size();
        for(int i = n-2; i >=0; i--){
            if(nums[i] < nums[i+1]){
                // int temp = nums[i];
                int min = i+1;
                for(int j = i+1; j < n; j++){
                    if(nums[j] > nums[i] && nums[min] > nums[j]) min = j;
                }
                swap(nums[min],nums[i]);
                sort(nums.begin()+i+1, nums.end());
                return;
            }
        }
        reverse(nums.begin(),nums.end());
    }
};