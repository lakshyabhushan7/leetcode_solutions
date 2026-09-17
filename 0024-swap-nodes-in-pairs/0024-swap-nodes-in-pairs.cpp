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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *prev = dummy;
        
        while(prev->next!=NULL && prev->next->next!=NULL){
            ListNode *node1 = prev->next;
            ListNode *node2 = prev->next->next;
            
            prev->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            
            prev = node1;
        }
        
        ListNode *newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};