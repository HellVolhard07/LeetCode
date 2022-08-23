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
public:
    
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(head) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        if(!head or !head->next) {
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next and fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow;
        mid->next = reverse(slow->next);
        mid = mid->next;
        while(mid) {
            if(head->val != mid->val) {
                return false;
            }
            head = head->next;
            mid = mid->next;
        }
        return true;
    }
};