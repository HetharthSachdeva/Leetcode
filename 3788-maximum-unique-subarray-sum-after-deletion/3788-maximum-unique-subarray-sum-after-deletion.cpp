class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> s;
        for(int i: nums) if(i>0) s.insert(i);
        if(s.size()==0) return *max_element(nums.begin(), nums.end());
        int ans = 0;
        for(int i: s) ans+=i;
        return ans;
    }
};