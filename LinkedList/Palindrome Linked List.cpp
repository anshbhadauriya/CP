Reach to second half of linked list  (mid ke bad)

Reverse second half

Keep a pointer in starting of Linked List and a pointer in starting of second half(reverse)

compare them 


class Solution {
public:

ListNode* reverseLL(ListNode* head1){

    ListNode* prev=NULL;
    ListNode* curr=head1;

    
 
    while(curr){
        ListNode* next=curr->next;

        curr->next=prev;
        prev=curr;
        curr=next;
    }

    ListNode* ansh=prev;

    while(ansh){ cout<<ansh->val<<" "; ansh=ansh->next;}

    return prev;

}
    bool isPalindrome(ListNode* head) {
        if(!head->next) return true;

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast and fast->next){

            slow=slow->next;
            fast=fast->next->next;
        }

        //slow is now at middle

        cout<<"second half"<<" "<<slow->val<<endl;

        ListNode* temp1=reverseLL(slow);
        ListNode* temp2=head;

        while(temp1){
            if(temp2->val!=temp1->val) return false;

            temp2=temp2->next;
            temp1=temp1->next;
        }

        return true;
    }
};

