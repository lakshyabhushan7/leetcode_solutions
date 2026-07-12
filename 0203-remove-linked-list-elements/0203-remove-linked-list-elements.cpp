/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int v) {
        while (head != NULL && head->val == v) {
            head = head->next;
        }

        ListNode* temp = head;
        while (temp != NULL && temp->next != NULL) {
            if (temp->next->val == v) {
                ListNode* ptr = NULL;
                ptr = temp;
                ptr->next = ptr->next->next; 
            } else {
                temp = temp->next; 
            }
        }
        
        return head;
    }
};