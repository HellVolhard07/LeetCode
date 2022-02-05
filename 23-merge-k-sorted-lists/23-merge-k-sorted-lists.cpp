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
class Solution {
    
    void listToArray(ListNode* node, vector<int> &arr) {
        while(node) {
            arr.push_back(node->val);
            node = node->next;
        }
    }
    
    ListNode* arrayToList(vector<int> arr) {
        int n = arr.size();
        ListNode* head = new ListNode();
        ListNode* temp = head;
        for(int i = 0 ; i < n ; i++) {
            ListNode* current = new ListNode(arr[i]);
            temp->next = current;;
            temp = temp->next;
        }
        return head->next;
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) {
            return {};
        }
        if(n == 1) {
            return lists[0];
        }
        vector<int> list_array;
        for(int i = 0 ; i < n ; i++) {
            listToArray(lists[i], list_array);
        }
        sort(list_array.begin(), list_array.end());
        return arrayToList(list_array);
    }
};