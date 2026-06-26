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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL && list2 == NULL)
            return NULL;

        if (list1 == NULL)
            return list2;

        if (list2 == NULL)
            return list1;

        ListNode* temp = list1;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = list2;

        temp = list1;

        vector<int> v;

        while (temp != NULL) {
            v.push_back(temp->val);
            temp = temp->next;
        }

        sort(v.begin(), v.end());

        temp = list1;
        int i = 0;

        while (temp != NULL) {
            temp->val = v[i];
            temp = temp->next;
            i++;
        }

        return list1;
    }
};