class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> ans;
        map<int, int> f;
        for(int i: nums){
            f[i]++;
        }
        int n = nums.size();
        for(auto i: f){
            if(i.second> n/3){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};