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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* add = new TreeNode(val);
        if(!root) return add;
        TreeNode* ptr = root, *ptr2;
        if(ptr->val>val) ptr2 = ptr->left;
        else ptr2 = ptr->right;
        while(ptr2){
            ptr = ptr2;
            if(ptr2->val > val){
                ptr2 = ptr2->left;
            }
            else ptr2 = ptr2->right;
        }

        if(ptr->val > val) ptr->left = add;
        else ptr->right = add;

        return root;
    }
};