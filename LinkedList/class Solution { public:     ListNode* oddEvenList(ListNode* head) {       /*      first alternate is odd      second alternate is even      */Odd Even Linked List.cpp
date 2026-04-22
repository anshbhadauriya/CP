class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

     /*
     first alternate is odd
     second alternate is even
     */

     if(!head) return NULL;

     if(!head->next) return head;
 
     ListNode* odd=head;
     ListNode* even=head->next;
     ListNode* save=head->next;


     while(even and even->next){

        odd->next=even->next;

        odd=odd->next;

        even->next=odd->next;

        even=even->next;
        
     }


     odd->next=save;

     return head;

        
    }
};
