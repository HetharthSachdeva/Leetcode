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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val > key){
            root->left = deleteNode(root->left, key);
        }
        else if(root->val < key) root->right = deleteNode(root->right, key);
        
        else if(root->val==key){
            if(!root->left) return root->right ;
            if(!root->right) return root->left;

            TreeNode* ptr = root->right, *ptr2=NULL;
            while(ptr->left){
                ptr2 = ptr;
                ptr = ptr->left;
            }
            ptr->left = root->left;
            if(ptr2){
                ptr2->left = ptr->right;ptr->right = root->right;
            } 
            
            delete(root);
            return ptr;
        }
        return root;
    }
};