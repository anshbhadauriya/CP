/*

seperate 2 list

ek mid se pehle wali
ek mid se baad wali

mid se baad wali kro reverse kro

dono ko merge kro


 */
class Solution {
public:

ListNode* reverse(ListNode* temp){

    ListNode* curr=temp;
        ListNode* prev=NULL;

        while(curr){

            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }

        return prev;
}
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast and fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

       // cout<<slow->val<<endl;

        ListNode* temp=slow->next;

        slow->next=NULL;

        ListNode* list2=reverse(temp);

        ListNode* list1=head;

        // cout<<"list 1 head is "<<list1->val<<endl;
        // cout<<"list 2 head is "<<list2->val<<endl;


        while(list1 and list2){

            ListNode* save1=list1->next;
            ListNode* save2=list2->next;

            list2->next=list1->next;
            list1->next=list2;
            list1=save1;
            list2=save2;

        }




    }
};
