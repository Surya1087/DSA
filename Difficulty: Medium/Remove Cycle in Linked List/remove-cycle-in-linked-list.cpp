/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    void removeLoop(Node* head) {
           if(head==NULL || head->next==NULL){
           return;
       }
       bool iscycle = false;
       Node* slow = head;
       Node* fast = head;
       while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(fast==slow){
            iscycle = true;
            break;
            }
       }
       if (!iscycle) {
            return;
        }
        slow = head;
       if(slow == fast){
           while(fast->next != slow){
               fast = fast->next;
           }
               fast->next=NULL;
               return;
           }
           
           Node* prev = NULL;
           while(slow!=fast){
               prev=fast;
               slow=slow->next;
               fast=fast->next;
           }
           prev->next=NULL;
           
       
    }
};