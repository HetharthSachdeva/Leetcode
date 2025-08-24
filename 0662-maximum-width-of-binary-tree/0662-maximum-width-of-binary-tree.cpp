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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long>> q;
        q.push({root, 1});
        unsigned long long ans = 0;
        while(!q.empty()){
            
            int s= q.size();
            unsigned long long mi = ULLONG_MAX, ma = 0;
            unsigned long long l = q.front().second;
            for(int i = 0; i < s; i++){
                TreeNode* ptr = q.front().first;
                unsigned long long pos = q.front().second - l + 1;
                q.pop();
                mi = min(mi, pos);
                ma = max(ma, pos);
                if(ptr->left) q.push({ptr->left, 2*pos-1});
                if(ptr->right) q.push({ptr->right, 2*pos});
            }
            cout << ma <<endl<< mi << endl;
            ans = max(ans, ma-mi);
            
        }
        return ans+1;
    }
};