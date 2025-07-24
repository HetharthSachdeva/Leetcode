class Solution {
public:
    vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
    void dfs(vector<vector<int>>& grid, int x, int y){
        if((x<0) || (x>=grid.size()) || (y < 0) || (y>=grid[0].size()) || (grid[x][y] == 0)) return;
        grid[x][y] = 0;
        for(int i = 0; i < 4; i++){
            dfs(grid, x+dir[i][0], y+dir[i][1]);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        for(int i = 0; i < n; i++){
            dfs(grid, i, 0);
            dfs(grid, i, m-1);
        }
        for(int i = 0; i < m; i++){
            dfs(grid, 0, i);
            dfs(grid, n-1, i);
        }

        int ans = 0;
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(grid[i][j]== 1) ans++;
        return ans;
    }
};