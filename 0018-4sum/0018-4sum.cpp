class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        sort(nums.begin(), nums.end());
        long long n = nums.size();
        vector<vector<int>> ans;
        if (n < 4)
            return {};
        for (long long i = 0; i < n - 3; i++) {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            for (long long j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                long long k = j + 1, l = n - 1;
                while (k < l) {
                    long long sum =
                        (long long)nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                        while (k < l && nums[k] == nums[k - 1])
                            k++;
                        while (k < l && nums[l] == nums[l + 1])
                            l--;
                    } else if (sum < target)
                        k++;
                    else
                        l--;
                }
            }
        }

        return ans;
    }
};