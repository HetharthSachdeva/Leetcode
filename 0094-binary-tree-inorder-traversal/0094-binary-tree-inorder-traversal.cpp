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
    vector<int> inorderTraversal(TreeNode* root) {
        // vector<int> ans = helper(root);
        vector<int> ans;
        stack<TreeNode*> st;
        if(!root) return {};
        TreeNode* ptr = root;
        while(true){
            if(ptr!=NULL){
                st.push(ptr);
                ptr= ptr->left;
            }
            else{
                if(st.empty()) break;
                ptr = st.top();
                st.pop();
                ans.push_back(ptr->val);
                ptr = ptr->right;
            }
        }
        return ans;
    }
};