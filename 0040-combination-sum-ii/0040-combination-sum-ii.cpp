class Solution {
public:
    vector<vector<int>> ans;
    void help(vector<int>& c, vector<int> combo, int sum, int t, int i){
        if(sum==t){
            ans.push_back(combo);
            return;
        }
        if(sum>t || i>= c.size()) return;
        
        int j = i+1;
        while(j < c.size() && c[j]==c[j-1]){
            j++;
        }
        help(c, combo, sum, t, j);
        combo.push_back(c[i]);
        help(c, combo, sum+c[i], t, i+1);

        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> k;
        help(candidates, k, 0, target, 0);
        return ans;
    }
};