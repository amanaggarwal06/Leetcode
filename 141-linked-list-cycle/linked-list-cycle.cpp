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
    bool hasCycle(ListNode *head) {
        
        //edge cases
        if(head == NULL){
            return false;
        }
        else if(head->next == head){
            return true;
        }

        unordered_map<ListNode*, bool> mp;
        ListNode*temp = head;

        while(temp!= NULL){

            if(mp[temp]){
               return true;
            }
            
            mp[temp] = true;
            temp = temp->next;
        }

        return false;
    }
};