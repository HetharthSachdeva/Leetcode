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
    int count(TreeNode* node){
        if(!node) return 0;
        return 1 + count(node->left) + count(node->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        int j = count(root->left);
        if(k == j+1) return root->val;
        else if(k > j){
            return kthSmallest(root->right, k-j-1);
        }
        else return kthSmallest(root->left, k);
    }
};