class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n= matrix.size();
        int m = matrix[0].size();

        int i = 0, j = m*n-1;
        while(i <= j){
            int mid = i + (j-i)/2;
            int x = mid/m, y = mid%m;
            if(matrix[x][y] == target ) return true;
            else if(matrix[x][y] < target) i = mid+1;
            else j = mid-1;
        }
        // if(matrix[i/m][i%m] == target) return true;
        return false;
    }
};