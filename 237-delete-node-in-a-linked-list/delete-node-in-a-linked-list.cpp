/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        
        ListNode* prev = NULL;
        ListNode* head = node;

        while(head->next != NULL){

            swap(head->val, head->next->val);
            prev = head;
            head = head->next;
        }

        prev->next = NULL;
        return;

    }
};