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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        //edge case
        if(list1 == list2) return list1;
        ListNode* temp; ListNode* temp2;
        ListNode* head = list1;

        int cnt = 0;
        while(cnt < a-1){
            head = head->next;
            cnt++;
        }

        temp = head;

        while(cnt < b){
            head = head->next;
            cnt++;
        }

        temp->next = list2;

        while(list2->next != NULL){
            list2 = list2->next;
        }

        list2->next = head->next;

        return list1;


    }
};