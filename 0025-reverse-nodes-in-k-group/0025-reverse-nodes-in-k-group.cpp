class Solution {
private:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* temp = head;
        while (temp != NULL) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        // checking if there are k nodes
        for (int i = 0; i < k; i++) {
            if (temp == NULL)
                return head;
            temp = temp->next;
        }
        // reaching at kth node acc to question
        ListNode* curr = head;
        for (int i = 0; i < k - 1; i++) {
            curr = curr->next;
        }
        // assigning cuur->next and breaking list
        ListNode* nextGroupHead = curr->next;
        curr->next = NULL;
        // reversing k elements
        ListNode* reversedHead = reverse(head);
        // using reccursion until null
        head->next = reverseKGroup(nextGroupHead, k);

        return reversedHead;
    }
};