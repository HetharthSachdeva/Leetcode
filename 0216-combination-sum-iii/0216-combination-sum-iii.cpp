class Solution {
public:
    vector<vector<int>> ans;
    void help(int target, int i, vector<int> combo, int l){
        if(combo.size()>l) return;
        if(target<0 || (target==0 && combo.size()!=l)) return;
        if(target == 0 && combo.size()==l){
            ans.push_back(combo);
            return;
        }
        if(i > 9) return;
        for(int j = i; j <= 9; j++){
            combo.push_back(j);
            help(target-j, j+1, combo, l);
            combo.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> j;
        help(n, 1,j , k);
        return ans;
    }
};