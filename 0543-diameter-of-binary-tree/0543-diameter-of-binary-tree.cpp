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
    int ans = 0;

    int maxd(TreeNode* k){
        if(!k) return 0;
        int l = maxd(k->left);
        int r = maxd(k->right);
        if(ans < l+r) ans = l+r;
        return 1 + (max(l,r));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int h= maxd(root);
        return ans;
    }
};