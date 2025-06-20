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
    bool isOpp(TreeNode* one, TreeNode* two){
        if(one && !two || !one && two) return false;
        if(!one && !two) return true;
        if(one->val != two->val ) return false;

        return isOpp(one->left, two->right) && isOpp(one->right, two->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        TreeNode* ptr1 = root->left;
        TreeNode* ptr2 = root->right;
        return isOpp(ptr1, ptr2);
    }
};