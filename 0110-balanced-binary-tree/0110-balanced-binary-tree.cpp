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
        
        int c = maxd(a->left);
        int b = maxd(a->right);
        if(c==-1 || b==-1) return -1;
        if(abs(c-b) > 1) return -1;
        return 1 + max(c,b);
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int h1 = maxd(root->left);
        int h2 = maxd(root->right);
        if(h1==-1 || h2==-1) return false;
        return (abs(h1-h2) < 2 );
    }
};