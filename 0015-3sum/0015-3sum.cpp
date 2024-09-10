class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            int j = i + 1, k = n - 1;
            if(nums[i]>0) break;
            while (j < k) {
                if (nums[j] + nums[k] + nums[i] == 0) {
                    ans.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                } else if (nums[j] + nums[k] + nums[i] > 0) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        vector<vector<int>> ans2;
        for (auto i : ans) {
            ans2.push_back(i);
        }
        return ans2;
    }
};