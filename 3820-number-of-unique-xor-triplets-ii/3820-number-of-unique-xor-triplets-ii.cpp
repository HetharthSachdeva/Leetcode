class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> s;
        unordered_set<int> ans;
        for(int i= 0; i < n; i++){
            for(int j = i; j < n; j++) s.insert(nums[i]^nums[j]);
        }

        for(auto i : s){
            for(int j : nums) ans.insert(i^j);
        }
        
        return ans.size();
    }
};