/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* node, vector<vector<int>>& list){
        if(!node) return;
        if(node->left){
            list[node->val].push_back(node->left->val);
            list[node->left->val].push_back(node->val);
            dfs(node->left, list);
        }
        if(node->right){
            list[node->val].push_back(node->right->val);
            list[node->right->val].push_back(node->val);
            dfs(node->right, list);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(k==0) return {target->val};
        vector<vector<int>> adj(501);
        dfs(root, adj);
        vector<bool> vis(501, false);
        queue<int> q;
        q.push(target->val);
        while(!q.empty() && k--){
            int s = q.size();
            while(s--){
                int u = q.front();
                q.pop();
                vis[u] = true;
                for(int i = 0; i < adj[u].size(); i++){
                    if(!vis[adj[u][i]]) q.push(adj[u][i]);
                }
            }
        }
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};