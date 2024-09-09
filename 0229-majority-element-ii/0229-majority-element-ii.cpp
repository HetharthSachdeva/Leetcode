class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
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