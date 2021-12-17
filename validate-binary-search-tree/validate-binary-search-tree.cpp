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

int64_t minimum(TreeNode* root) {
    if(!root) {
        return INT64_MAX;
    }
    return min((int64_t)root->val, min(minimum(root->left), minimum(root->right)));
}

int64_t maximum(TreeNode* root) {
    if(!root) {
        return INT64_MIN;
    }
    return max((int64_t)root->val, max(maximum(root->left), maximum(root->right)));
}

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) {
            return true;
        }
        bool output = root->val > maximum(root->left) and root->val < minimum(root->right) and isValidBST(root->left) and isValidBST(root->right);
        return output;
    }
};