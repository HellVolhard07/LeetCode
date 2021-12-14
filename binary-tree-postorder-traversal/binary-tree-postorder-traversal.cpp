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
void postorderHelper(TreeNode* root, vector<int> &preorder) {
    if(!root) {
        return;
    }
    postorderHelper(root->left, preorder);
    postorderHelper(root->right, preorder);
    preorder.push_back(root->val);
}
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) {
            return {};
        }
        vector<int> preorder;
        postorderHelper(root, preorder);
        return preorder;
    }
};