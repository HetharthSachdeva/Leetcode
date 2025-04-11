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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return {};
        if(root->left!=NULL){
            vector<int> l = postorderTraversal(root->left);
            ans.insert(ans.end(), l.begin(), l.end());
        }
        
        if(root->right!=NULL){
            vector<int> r = postorderTraversal(root->right);
            ans.insert(ans.end(), r.begin(), r.end());
        }
        ans.push_back(root->val);
        return ans;
    }
};