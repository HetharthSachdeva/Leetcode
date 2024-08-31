class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n%2 == 0){
            for(int i = 0; i < (n/2); i++){
                for(int j = 0; j < (n/2); j++){
                    swap(matrix[i][j], matrix[j][n-1-i]);
                    swap(matrix[i][j], matrix[n-j-1][i]);
                    swap(matrix[n-j-1][i], matrix[n-i-1][n-j-1]);
                }
            }
        }
        else{
            for(int i = 0; i < n; i++){
                for(int j = i; j < n; j++){
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n/2; j++){
                    swap(matrix[i][j], matrix[i][n-j-1]);
                }
            }    
        }
    }
};