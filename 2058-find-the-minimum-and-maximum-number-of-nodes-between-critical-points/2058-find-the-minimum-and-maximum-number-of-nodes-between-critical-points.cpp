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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL) {
            return {-1, -1};
        }

        int mn = INT_MAX;
        int mx = -1;
        vector<int> v;
        
        ListNode* prev = head;
        ListNode* temp = head->next;
        int i = 1; 

        while (temp->next != NULL) {
            if ((prev->val < temp->val && temp->val > temp->next->val) || 
                (prev->val > temp->val && temp->val < temp->next->val)) {
                v.push_back(i); 
            }
            
            i++; 
            prev = temp; 
            temp = temp->next; 
        } 
        
        if (v.size() < 2) {
            return {-1, -1};
        }

        for(int j = 0; j < (v.size() - 1); j++){
            mn = min(mn, v[j+1] - v[j]); 
        } 
        mx = v[v.size() - 1] - v[0]; 
        
        return {mn, mx};
    }
};