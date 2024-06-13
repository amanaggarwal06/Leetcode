/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        //edge cases
        if(head == NULL) return NULL;
        
        Node* dummy = new Node(-1);

        //insert copy nodes into the orig LL
        Node* temp = head;
        while(temp != NULL){

            Node* copynode = new Node(temp->val);
            Node* fwd = temp->next;

            temp->next = copynode;
            copynode->next = fwd;
            temp = fwd;
        }

        //copyLL head
        dummy->next = head->next;

        //Link random pointers of copy LL

        temp = head;

        while(temp != NULL){

            Node* copynode = temp->next;

            if(temp->random != NULL){
                copynode->random = temp->random->next;
            }
            else{
                copynode->random = NULL;
            }
            
            temp = copynode->next;
        }

        //extracting copy LL from merged LL
        temp = head;
        while(temp != NULL){

            Node* copynode = temp->next;
            temp->next = copynode->next;

            if(copynode->next != NULL){
                copynode->next = copynode->next->next;
            }
            else{
                copynode->next = NULL;
            }

            temp = temp->next;
        }

        return dummy->next;

    }
};