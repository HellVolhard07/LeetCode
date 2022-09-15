/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    
    TreeNode* withoutSpace(ListNode* head, ListNode* tail) {
        if(head == tail) {
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != tail and fast->next != tail) {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* root = new TreeNode(slow->val);
        root->left = withoutSpace(head, slow);
        root->right = withoutSpace(slow->next, tail);
        return root;
    }
    
    TreeNode* withSpace(vector<int> &nodes, int start, int end) {
        if(start > end) {
            return NULL;
        }
        int mid = (start + end) / 2;
        TreeNode* root = new TreeNode(nodes[mid]);
        root->left = withSpace(nodes, start, mid - 1);
        root->right = withSpace(nodes, mid + 1, end);
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nodes;
        while(head) {
            nodes.push_back(head->val);
            head = head->next;
        }
        return withSpace(nodes, 0, nodes.size() - 1);
    }
};