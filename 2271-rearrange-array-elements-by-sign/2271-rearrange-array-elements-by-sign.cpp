class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> numseven, numsodd;
        int n = nums.size();
        vector<int> ans;
        for(int i: nums){
            if(i>0) numseven.push_back(i);
            else numsodd.push_back(i);
        }
        for(int j = 0; j < (n+1)/2; j++){
            ans.push_back(numseven[j]);
            ans.push_back(numsodd[j]);
        }
        return ans;
    }
};