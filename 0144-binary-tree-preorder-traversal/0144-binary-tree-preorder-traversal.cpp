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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nodes;
        TreeNode* ptr = root;
        stack<TreeNode*> st;
        if(!root) return {};
        st.push(ptr);
        while(!st.empty()){
            ptr = st.top();
            st.pop();
            nodes.push_back(ptr->val);
            if(ptr->right) st.push(ptr->right);
            if(ptr->left) st.push(ptr->left);
        }
        return nodes;
    }
};