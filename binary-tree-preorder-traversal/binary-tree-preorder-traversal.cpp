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
void preOrderHelper(TreeNode* root, vector<int> &preorder) {
    if(!root) {
        return;
    }
    preorder.push_back(root->val);
    preOrderHelper(root->left, preorder);
    preOrderHelper(root->right, preorder);
}
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) {
            return {};
        }
        vector<int> preorder;
        preOrderHelper(root, preorder);
        return preorder;
    }
};