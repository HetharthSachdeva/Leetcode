class Solution {
public:
    int dfs(int node, vector<int>& states, vector<vector<int>>& adj, vector<bool>& path){
        if(states[node]!=0) return states[node];
        if(path[node]){
            return -1;
        }
        path[node] = true;
        bool flag = true;
        for(auto i: adj[node]){
            states[i] = dfs(i, states, adj, path);
            flag = flag & (states[i]>0);
        }
        if(flag) return 1;
        else return -1;
        path[node] = false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans, state(n, 0);
        vector<bool> v(n, false);

        for(int i = 0; i < n; i++){
            if(state[i]==0){
                state[i] = dfs(i, state, graph, v);
            }
        }

        for(int i = 0; i < n; i++){
            if(state[i]==1) ans.push_back(i);
        }
        return ans;
    }
};