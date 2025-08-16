class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        queue<int> q;
        vector<int> indegree(n, 0), ans;
        vector<vector<int>> adj(n);

        for(auto i: pre){
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }

        for(int i = 0; i < n; i++){
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int k = q.front();
            q.pop();
            for(int i: adj[k]){
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
                if(indegree[i] < 0) return {};
            }

            ans.push_back(k);
        }
        if(ans.size() < n) return {};
        return ans;
    }
};