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
    vector<int> nodes;
    int i = -1;
    vector<int> inorder(TreeNode* root){
        vector<int> ans, ans2;
        if(!root) return {};
        ans = inorder(root->left);
        ans2 = inorder(root->right);
        ans.push_back(root->val);
        ans.insert(ans.end(), ans2.begin(), ans2.end());
        return ans;
    }
    BSTIterator(TreeNode* root) {
        nodes = inorder(root);
    }
    
    int next() {
        i++;
        return nodes[i];
    }
    
    bool hasNext() {
        if(i+1>=nodes.size()) return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */