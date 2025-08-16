class Solution {
public:
    bool dfs(int node, vector<vector<int>>& list, vector<bool>& path, vector<bool>& visited, stack<int>& topo){
        visited[node] = true;
        path[node] = true;
        for(auto i : list[node]){
            if(path[i]) return false;
            if(!visited[i]){
                if((!dfs(i, list, path, visited, topo))) return false;
            }
        }
        path[node] = false;
        topo.push(node);
        return true;
    }

    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        stack<int> st;
        vector<int> ans;
        vector<bool> vis(n, false), path(n, false);
        vector<vector<int>> adj(n);

        for(auto i: pre){
            adj[i[1]].push_back(i[0]);
        }

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                if(!dfs(i, adj, path, vis, st)) return {};
            }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        // reverse(ans.begin(), ans.end());
        return ans;
    }
};