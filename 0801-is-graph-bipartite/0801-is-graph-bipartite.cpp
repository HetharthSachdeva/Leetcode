class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& v, int color){
        if(v[node]!=-1){
            if(v[node]==color) return true;
            return false;
        }

        v[node] = color;
        bool ans = true;
        for(auto i: graph[node]){
            ans= ans&dfs(i, graph, v, 1-color);
        }
        return ans;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> visited(graph.size(), -1);
        if(graph.size()==0) return false;
        bool ans = true;
        for(int i = 0; i < graph.size(); i++){
            if(graph[i].size()!=0 && visited[i]==-1) ans&= dfs(i, graph, visited, 1);
        }
        return ans;
    }
};