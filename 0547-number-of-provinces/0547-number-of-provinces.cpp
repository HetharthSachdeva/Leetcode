class Solution {
public:
    void dfs(int node, vector<int> list[], vector<int>& v){
        for(int i = 0; i < list[node].size(); i++){
            if(!v[list[node][i]]){
                v[list[node][i]]=1;
                dfs(list[node][i], list, v);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& iscon) {
        int n = iscon.size();
        vector<int> list[n], visited(n, 0);
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(iscon[i][j]==1){
                    list[i].push_back(j);
                    list[j].push_back(i);
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                ans++;
                dfs(i, list, visited);
            }
        }
        return ans;
    }
};