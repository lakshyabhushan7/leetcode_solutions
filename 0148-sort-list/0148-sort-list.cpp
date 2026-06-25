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
private:
    ListNode* findmiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next; 
        
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* list1, ListNode* list2) {
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;
        
        ListNode* head = NULL;
        if (list1->val < list2->val) {
            head = list1;
            list1 = list1->next;
        } else {
            head = list2;
            list2 = list2->next; 
        }
        
        ListNode* ptr = head;
        
        while (list1 != NULL && list2 != NULL) {
            if (list1->val < list2->val) {
                ptr->next = list1;
                list1 = list1->next;
            } else {
                ptr->next = list2;
                list2 = list2->next;
            }
            ptr = ptr->next;
        }
        
        if (list1 != NULL) {
            ptr->next = list1;
        } else {
            ptr->next = list2;
        }
        
        return head;
    }

public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) 
            return head;
            
        ListNode* middle = findmiddle(head);
        ListNode* lefthead = head;
        ListNode* righthead = middle->next;
        
        middle->next = NULL; 
        
        lefthead = sortList(lefthead);
        righthead = sortList(righthead);
        
        return merge(lefthead, righthead);
    }
};