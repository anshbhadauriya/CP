class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        //isme second middle delete krna hai

        ListNode* slow=head;

        ListNode* fast=head;

        if(!head->next) return NULL;

        while(fast and fast->next){

            slow=slow->next;

            fast=fast->next->next;


        }

        cout<<"center is "<<slow->val<<endl;


        ListNode* temp=head;

        while(temp){

            if(temp->next==slow){

                temp->next=temp->next->next;

                delete slow;

                break;
            }

            temp=temp->next;

        }

        return head;
        
    }
};
