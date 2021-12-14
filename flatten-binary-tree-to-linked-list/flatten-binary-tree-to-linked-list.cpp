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
void preorderTraversal(TreeNode* root, vector<int> &nodes) {
    if(!root) {
        return;
    }
    nodes.push_back(root->val);
    preorderTraversal(root->left, nodes);
    preorderTraversal(root->right, nodes);
}
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) {
            return;
        }
        vector<int> nodes;
        preorderTraversal(root, nodes);
        root->val = nodes[0];
        root->left = NULL;
        root->right = NULL;
        if(nodes.size() == 1) {
            return;
        }
        TreeNode* temp = root;
        for(int i = 1 ; i <nodes.size() ; i++) {
            TreeNode* node = new TreeNode(nodes[i]);
            temp->right = node;
            temp = temp->right;
        }
    }
};