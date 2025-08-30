class Solution {
public:
    bool dfs(vector<vector<char>>& board, int x, int y, string& word, int i){
        int n = board.size(), m = board[0].size();
        if(board[x][y] != word[i]) return false;
        if(i==word.size()-1) return true;
        char temp = board[x][y];
        board[x][y] = '#';
        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0,1}, {0, -1}};
        bool ans = false;
        for(int h = 0; h < 4; h++){
            if(x+dir[h][0] < n && x+dir[h][0] >= 0 && y+dir[h][1] < m && y+dir[h][1] >= 0){ ans |= dfs(board, x+dir[h][0], y + dir[h][1], word, i+1); 
            if(ans){
                board[x][y] = temp;
                return true;
            }
            }
        }
        board[x][y] = temp;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int k = word.size();
        int n = board.size(), m = board[0].size();
        unordered_map<char,int> bc;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                bc[board[i][j]]++;

        unordered_map<char,int> wc;
        for(char c : word) wc[c]++;

        for(auto &p : wc)
            if(bc[p.first] < p.second) return false;
        bool ans = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans|=dfs(board, i, j, word, 0);
                if(ans) return true;
            }
        }
        return false;
    }
};