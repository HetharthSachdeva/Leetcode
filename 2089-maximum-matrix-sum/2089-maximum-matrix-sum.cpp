class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int k = INT_MIN;
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                sum+=abs(matrix[i][j]);
                 if(abs(matrix[i][j]) < abs(k))
                    k= abs(matrix[i][j]);
                if(matrix[i][j] <= 0){
                   
                    count++;
                } 
                 
            }
        }
        if(count%2 == 0){
            return sum;
        } 
        else return sum-2*k;
    }
};