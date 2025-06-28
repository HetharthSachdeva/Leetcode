/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> path(TreeNode* root, TreeNode* target){
        if(!root || !target) return {};
        if(root==target){
            return {target};
        }

        vector<TreeNode*> l = path(root->left, target);
        vector<TreeNode*> r = path(root->right, target);
        // if(l.size() == 0 && r.size()==0) return {};
        vector<TreeNode*> v = {root};
        if(r.size()){
            v.insert(v.end(), r.begin(), r.end());
            return v;
        }
        else if(l.size()){
            v.insert(v.end(), l.begin(), l.end());
            return v;
        }
        return {};

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> a = path(root, p), b = path(root, q);
        TreeNode* ans;
        for(int i= 0; i < min(a.size(), b.size()); i++){
            if(a[i]==b[i]) ans = a[i];
            else break;
        }
        return ans;
    }
};