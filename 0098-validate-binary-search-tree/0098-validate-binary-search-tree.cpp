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
    int min(TreeNode* node){
        if(node->left) return min(node->left);
        return node->val;
    }
    int max(TreeNode* node){
        if(node->right) return max(node->right);
        return node->val;
    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        long long a=INT_MAX+1LL, b=INT_MIN-1LL;

        if(root->right)
        a = min(root->right);
        if(root->left) b= max(root->left);
        if((root->val < a) && (root->val > b)) return isValidBST(root->left ) && isValidBST(root->right);
        

        return false;
    }
};