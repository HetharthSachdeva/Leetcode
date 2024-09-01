class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        
        vector<vector<int>> ans(m);
        int s = original.size();
        if((m*n) != s) return {};
        int i = 0;
        while(i < s){
            ans[i/n].push_back(original[i]);
            i++;
        }
        return ans;
    }
};