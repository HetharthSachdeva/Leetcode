class Solution {
public:
    vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
    void dfs(vector<vector<char>>& grid, int x, int y){
        if((x<0) || (x>=grid.size()) || (y < 0) || (y>=grid[0].size()) || (grid[x][y] == 'X') || (grid[x][y] == '#')) return;
        grid[x][y] = '#';
        for(int i = 0; i < 4; i++){
            dfs(grid, x+dir[i][0], y+dir[i][1]);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        
        for(int i = 0; i < n; i++){
            if(board[i][0]=='O'){
                dfs(board, i, 0);
            }
            if(board[i][m-1] == 'O') dfs(board, i , m-1);
        }

        for(int i = 0; i < m; i++){
            if(board[0][i] == 'O') dfs(board, 0, i);
            if(board[n-1][i] == 'O') dfs(board, n-1, i);
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j]=='#') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
    }
};