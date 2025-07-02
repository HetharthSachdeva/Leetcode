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
    TreeNode* find(vector<int>& preorder, int i, int j){
        int k = -1;
        if(i>j) return NULL;
        TreeNode* root = new TreeNode(preorder[i]);
        for(int l = i+1; l < j+1; l++){
            if(preorder[l]>root->val){
                k = l-1;
                break;
            }
        }
        if(k>-1){
            root->left = find(preorder, i+1, k);
            root->right = find(preorder, k+1, j);
        }
        else root->left = find(preorder, i+1, j);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==0) return NULL;
        return find(preorder,0,preorder.size()-1);
    }
};