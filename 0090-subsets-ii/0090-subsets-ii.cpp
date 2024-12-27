class Solution {
public:
    set<vector<int>> ans;
    void helper(vector<int>& a, vector<int> b, int index){
        if(index==a.size()){
            sort(b.begin(),b.end());
            ans.insert(b);
            return;
        }
        helper(a, b, index+1);
        b.push_back(a[index]);
        helper(a,b,index+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> v;
        helper(nums, v, 0);
        vector<vector<int>> g(ans.begin(),ans.end());
        
        return g;
    }
};