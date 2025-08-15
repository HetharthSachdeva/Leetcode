class Solution {
public:
    bool dfs(int node, vector<bool>& vis, vector<bool>& visi, vector<int> list[]){
        vis[node] = true;
        visi[node] = true;
        for(auto i : list[node]){
            if(visi[i]) return false;
            visi[i] = true;
            if(!vis[i]) if(!dfs(i, vis, visi, list)) return false;
            visi[i] = false;
        }
        return true;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<bool> vis(n, false), visi(n, false);

        vector<int> adj[n];
        for(int i = 0; i < pre.size(); i++){
            adj[pre[i][0]].push_back(pre[i][1]); 
        }

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                if(!dfs(i, vis, visi, adj)){
                    return false;
                } 
                visi[i] = false;
            }
            
        }
        return true;
    }
};