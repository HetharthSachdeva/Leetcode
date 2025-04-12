/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        TreeNode* ptr = root;
        queue<TreeNode*> q;
        if(!root) return {};
        q.push(ptr);
        while(!q.empty()){
            vector<int> level;
            int s= q.size();
            for(int i = 0; i < s; i++){
                ptr = q.front();
                q.pop();
                level.push_back(ptr->val);
                if(ptr->left) q.push(ptr->left);
                if(ptr->right) q.push(ptr->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};