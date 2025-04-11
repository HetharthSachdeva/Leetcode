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
    void helper(TreeNode* node, vector<int>& ans){
        if(!node) return;
        ans.push_back(node->val);
        if(node->left) helper(node->left, ans);
        if(node->right) helper(node->right, ans);
        return; 
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nodes;
        // TreeNode* ptr = root;
        // stack<TreeNode*> st;
        // st.push(ptr);
        // while(!st.empty()){
        //     ptr = st.top();
        //     nodes.push_back(ptr->val);
        //     if(ptr->left) st.push(ptr->left);
        //     if(ptr->right) st.push(ptr->right);
        // }
        // return nodes;

        helper(root, nodes);
        return nodes;
    }
};