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

    ListNode* reverseK(ListNode* head, int &cnt, int k){

        //base condn
        if(head == NULL || cnt < k){
            return head;
        }

        ListNode* prev = NULL; ListNode* temp = head;
        int K = k;

        while(k--){

            ListNode* fwd = temp->next;
            temp->next = prev;
            prev = temp;
            temp = fwd;
            cnt--;
        }

        head->next = reverseK(temp, cnt, K);

        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        int cnt = 0;
        ListNode* temp = head;

        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }

        return reverseK(head, cnt, k);


    }
};