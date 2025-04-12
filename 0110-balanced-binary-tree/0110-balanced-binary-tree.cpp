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
    int maxd(TreeNode* a){
        if(!a) return 0;
        return 1 + max(maxd(a->left),maxd(a->right));
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        return (abs(maxd(root->left)-maxd(root->right)) < 2 && isBalanced(root->left) && isBalanced(root->right));
    }
};