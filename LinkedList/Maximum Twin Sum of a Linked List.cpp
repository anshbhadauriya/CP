/*

find total nodes

reverse second half of ll

check first half and second half max twin

worked!

or u could have used slow fast pointer to find mid 


 */
class Solution {
public:

ListNode* reverse(ListNode* temp1){

    ListNode* curr=temp1;
    ListNode* prev=NULL;
    while(curr){

        ListNode* nextt=curr->next;

        curr->next=prev;
        prev=curr;
        curr=nextt;
    }

    return prev;
}
    int pairSum(ListNode* head) {

        // 1  2  3  4  5  5  4  3  2  1

        //////////////////1  2  3  4  5 

        //find size

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast and fast->next and fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }

       

        ListNode* temp1=slow->next;

        slow->next=NULL;
        ListNode* right=reverse(temp1);

        ListNode* left=head;
        int maximum=-1;
        while(left and right){

            // cout<<"left is "<<left->val<<endl;
            // cout<<"right is "<<right->val<<endl;
            maximum=max(maximum,left->val+right->val);
            left=left->next;
            right=right->next;
        }
        return maximum;
        
    }
};

/*
TC-> O(n)
Sc-> O(1)
*/
