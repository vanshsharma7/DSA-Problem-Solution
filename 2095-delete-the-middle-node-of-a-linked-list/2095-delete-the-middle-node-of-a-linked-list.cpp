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
    ListNode* slowfast(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=NULL){
            fast= fast->next;
            if(fast != NULL){
                fast = fast -> next;
            }
            slow = slow -> next;
        }
        return slow;
    }
public:
    ListNode* deleteMiddle(ListNode* head) {
      //  if(head -> next -> next == NULL){
       //     delete head->next;
         //   return head;
       // }
       if(head == NULL || head->next == NULL){
           return NULL;
       }
        

        ListNode* current = head;
        ListNode* previous = NULL;
        ListNode* slow = slowfast(head);
        while(current != slow){
            previous = current;
            current = current -> next;
        }
        previous -> next = current -> next;
        current -> next = NULL;
        delete current;
        return head;
    }
};