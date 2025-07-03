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
class BSTIterator {
public:
    stack<TreeNode*> st;

    BSTIterator(TreeNode* root) {
        TreeNode* ptr = root;
        while(ptr->left){
            st.push(ptr);
            ptr = ptr->left;
        }
        st.push(ptr);
    }
    
    int next() {
        TreeNode* ptr = st.top();
        int ans = ptr->val;
        st.pop();
        if(ptr->right){
            ptr=ptr->right;
            st.push(ptr);
            while(ptr->left){
                ptr = ptr->left;
                st.push(ptr);
            }
        }

        return ans;
    }
    
    bool hasNext() {
        if(st.empty()) return false;
        else return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */