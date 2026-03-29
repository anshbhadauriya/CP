Iterative->

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* prev=NULL;
        ListNode* curr=head;

        while(curr!=NULL){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;   //agar direct curr=curr->next krte too curr previous me point hota kyuki curr->next too prev hai
        } 


        return prev;
        
    }
};


Recursive->

