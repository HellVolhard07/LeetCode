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
    ListNode* swapNodes(ListNode* node1, ListNode* node2, ListNode* &previous) {
        node1->next = node2->next;
        node2->next = node1;
        if(previous) {
            previous->next = node2;
        }
        else {
            previous = node1;
        }
        return node2;
    }
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp = head;
        ListNode* previous;
        while(temp and temp->next) {
            if(temp == head) {
                previous = NULL;
                temp = swapNodes(temp, temp->next, previous);
                head = temp;
            }
            else {
                temp = swapNodes(temp, temp->next, previous);
                previous = temp->next;
            }
            temp = temp->next->next;
        }
        return head;
    }
};