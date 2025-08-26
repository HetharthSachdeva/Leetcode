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
    void maxSum(TreeNode* node, int& sum, int& ans){
        if(!node) return;
        sum+= node->val;
        ans = max(ans, sum);
        maxSum(node->left, sum, ans);
        maxSum(node->right, sum, ans);
        sum-=node->val;
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return INT_MIN;
        int ans = 0, sum=0, ans2 = 0;
        maxSum(root->left, sum, ans);
        sum = 0;
        maxSum(root->right, sum, ans2);
        return max(maxPathSum(root->left), max(maxPathSum(root->right), root->val+ans+ans2));
    }   
};