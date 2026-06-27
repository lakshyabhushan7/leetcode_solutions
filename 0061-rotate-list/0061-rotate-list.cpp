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
    ListNode* rotateRight(ListNode* head, int k) {

        if (head == NULL || head->next == NULL || k == 0)
            return head;

        int n = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            n++;
            temp = temp->next;
        }

        k = k % n;

        if (k == 0)
            return head;

        vector<int> v;

        temp = head;

        for (int i = 0; i < n - k; i++)
            temp = temp->next;

        while (temp != NULL) {
            v.push_back(temp->val);
            temp = temp->next;
        }

        temp = head;

        for (int i = 0; i < n - k; i++) {
            v.push_back(temp->val);
            temp = temp->next;
        }

        temp = head;
        int i = 0;

        while (temp != NULL) {
            temp->val = v[i++];
            temp = temp->next;
        }

        return head;
    }
};