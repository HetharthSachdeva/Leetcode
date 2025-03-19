class Solution {
public:
    void helper(vector<int>& arr, vector<bool> taken, vector<vector<int>>& a, vector<int> combo, int ind){
        if(ind>= arr.size()){
            a.push_back(combo);
            return;
        }

        for(int i = 0; i < arr.size(); i++){
            if(!taken[i]){
                combo.push_back(arr[i]);
                taken[i] = true;
                helper(arr, taken, a, combo, ind+1);
                combo.pop_back();
                taken[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<bool> co(n, false);
        vector<int> combo;
        helper(nums, co, ans,combo, 0);
        return ans;
    }
};