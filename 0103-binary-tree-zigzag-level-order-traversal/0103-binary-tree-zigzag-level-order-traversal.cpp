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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return {};
        queue<TreeNode*> q;bool flag = false;
        q.push(root);
        while(!q.empty()){
            vector<int> level;
            int s = q.size();
            for(int i = 0; i < s; i++){
                TreeNode* ptr = q.front();
                q.pop();
                if(ptr)
                level.push_back(ptr->val);
                else continue;
                q.push(ptr->left);
                q.push(ptr->right);
            }
            if(flag){
                reverse(level.begin(), level.end());
            }
            flag = !flag;
            if(level.size()!=0) ans.push_back(level);
            else break;
        }
        return ans;
    }
};