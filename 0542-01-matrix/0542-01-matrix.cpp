class Solution {
public:
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, n+m));
        queue<vector<int>> q;
        for(int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    ans[i][j] = 0;
                    q.push({i,j});
                } 
            }
        }
        int dist = 0;
        while(!q.empty()){
            dist++;
            int s = q.size();
            vector<vector<int>> d = {{1,0},{-1,0},{0,1},{0,-1}};
            for(int i = 0; i < s; i++){
                int x = q.front()[0], y = q.front()[1];
                q.pop();
                for(int j = 0; j < 4; j++){
                    if((x+d[j][0] > -1) && (x+d[j][0] < n) && (y+d[j][1] > -1) && (y +d[j][1] < m)){
                        if(ans[x+d[j][0]][y+d[j][1]] > dist){
                            ans[x+d[j][0]][y+d[j][1]] = dist;
                            q.push({x+d[j][0], y+d[j][1]});
                        }
                    }
                }
            }
        }    
        return ans;
    }
};