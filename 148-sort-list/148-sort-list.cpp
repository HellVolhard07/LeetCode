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
    void createArray(ListNode* head, vector<int> &arr) {
        while(head) {
            arr.push_back(head->val);
            head = head->next;
        }
    }
    
    ListNode* createList(vector<int> arr) {
        int n = arr.size();
        if(n == 0) {
            return NULL;
        }
        ListNode* head = new ListNode(arr[0]);
        ListNode* temp = head;
        int i = 1;
        while(i < n) {
            ListNode* newNode = new ListNode(arr[i]);
            temp->next = newNode;
            temp = temp->next;
            i++;
        }
        return head;
    }
    
public:
    ListNode* sortList(ListNode* head) {
        vector<int> arr;
        createArray(head, arr);
        sort(arr.begin(), arr.end());
        head = createList(arr);
        return head;
    }
};