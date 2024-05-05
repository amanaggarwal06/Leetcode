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
        
        ListNode* fwd = node->next; ListNode* prev = NULL;

        while(fwd != NULL){
            swap(node->val, fwd->val);
            prev = node;
            node = fwd;
            fwd = node->next;
        }

        prev->next = NULL;
        
    }
};