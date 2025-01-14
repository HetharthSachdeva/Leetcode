class Solution {
public:
    vector<vector<int>> ans;
    void help(int target, int i, vector<int> combo, int l){
        if(target<0 || (target==0 && combo.size()!=l)) return;
        if(target == 0 && combo.size()==l){
            ans.push_back(combo);
            return;
        }
        if(i > 9) return;
        help(target, i+1, combo,l);
        combo.push_back(i);
        help(target - i, i+1, combo,l);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> j;
        help(n, 1,j , k);
        return ans;
    }
};