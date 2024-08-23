class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        unordered_map<int,int> m;
        for(int i =0; i < nums.size(); i++){
            m[nums[i]] = i;
        }
        for(int i =0 ; i < nums.size(); i++){
            if(m.find(target-nums[i]) != m.end() && m[target-nums[i]]!=i){
                return {i,m[target-nums[i]]};
            }
        } 
        return {};
    }
};