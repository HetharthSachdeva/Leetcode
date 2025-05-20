class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> k(nums.size(), 0);

        for(auto q: queries){
            k[q[0]]++;
            if(q[1]<nums.size()-1) k[q[1]+1]--;
        }
        for(int i = 1; i < nums.size(); i++){
            k[i]+=k[i-1];
        }
        for(int i = 0; i < nums.size(); i++){
            if(k[i] < nums[i]) return false;
        }
        return true;
    }
};