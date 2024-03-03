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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        //edge case
        if(head->next == NULL){
            if(n==1){
                return NULL;
            }

            return head;
        }

        ListNode* temp = head; int cnt = 0;
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }

        int del_pos = cnt-n; cnt =0;
        if(del_pos == 0) return head->next;
        else if(del_pos < 0) return head;

        temp = head;
        while(temp != NULL){
            cnt++;
            if(cnt == del_pos){
                
                if(temp->next != NULL){
                    temp->next = temp->next->next;
                }
                break;
            }
            else{
                temp = temp->next;
            }
        }

        return head;
    }
};