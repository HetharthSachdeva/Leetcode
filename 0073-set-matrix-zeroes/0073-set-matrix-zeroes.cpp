class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<pair<int, int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0)
                    ans.push_back({i, j});
            }
        }
        set<int> rows, cols;
        for (auto i : ans) {
            rows.insert(i.first);
            cols.insert(i.second);
        }
        for(int i : rows){
            for(int j = 0; j < m; j++){
                matrix[i][j] = 0;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j : cols){
                matrix[i][j] = 0;
            }
        }
    }
};