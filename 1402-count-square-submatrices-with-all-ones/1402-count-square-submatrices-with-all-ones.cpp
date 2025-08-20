class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> pre(n, vector<int>(m, 0));
        long long ans =0;
        pre[0][0] = matrix[0][0];
        for(int i = 1; i < n; i++){
            pre[i][0] = pre[i-1][0] + matrix[i][0];
        }
        for(int i = 1; i < m; i++){
            pre[0][i] = pre[0][i-1] + matrix[0][i];
        }
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                pre[i][j] = pre[i][j-1]+pre[i-1][j]-pre[i-1][j-1] + matrix[i][j];
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                for(int k = 0; k < n; k++){
                    if(i+k >= n || j+k>=m) break;
                    if(pre[i+k][j+k] - (j>0?pre[i+k][j-1]:0) - (i>0?pre[i-1][j+k]:0) + (i>0 && j>0?pre[i-1][j-1]:0)== (k+1)*(k+1)) ans++;
                    else break;
                }
            }
        }
        return ans;
    }
};