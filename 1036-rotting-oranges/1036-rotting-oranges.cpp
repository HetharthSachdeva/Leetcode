class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
        queue<vector<int>> q;
        int n = grid.size(), m = grid[0].size();

        for(int i = 0; i< n; i++){
            for(int j = 0; j < m;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int s = q.size();ans++;
            for(int i = 0; i < s; i++){
                vector<int> point = q.front();
                grid[point[0]][point[1]] = 2;
                q.pop();
                if(point[0]>0 && grid[point[0]-1][point[1]]==1){
                    q.push({point[0]-1, point[1]});
                    grid[point[0]-1][ point[1]] = 2;
                } 
                if(point[0]<n-1 && grid[point[0]+1][point[1]]==1){
                     q.push({point[0]+1, point[1]});
                     grid[point[0]+1][ point[1]] = 2;
                }     
                if(point[1]>0 && grid[point[0]][point[1]-1]==1){
                     q.push({point[0], point[1]-1});
                     grid[point[0]][point[1]-1] = 2;}
                if(point[1]<m-1 && grid[point[0]][point[1]+1]==1){
                    q.push({point[0], point[1]+1});
                    grid[point[0]][point[1]+1] = 2;
                } 
            }
        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return max(0,ans-1);
        
    }
};