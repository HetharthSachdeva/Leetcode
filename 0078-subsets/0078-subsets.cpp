class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i = 0; i < (1<<n); i++){
            vector<int> combo;
            int k = i;
            for(int j = 0; j < n; j++){
                if(k&1) combo.push_back(nums[j]);
                k = k >> 1;
            }
            ans.push_back(combo);
        }
        return ans;
    }
};