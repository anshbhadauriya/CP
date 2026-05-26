class Solution {
public:

/*

Basically isme mergesort perform krna hai

So all u need to do is:

Find mid 

Break LL in 2 parts

Keep breaking

Now Merge with condition of:

jo chota usko pehle place krdo aur pointer aage bda do


Divide krte time left segment ke end me NULL mark kr dena to make them seperated from right
like this thiss mid->next=NULL;

*/

ListNode* findMid(ListNode* head){

    ListNode* slow=head;
    ListNode* fast=head;

    while(fast and fast->next and fast->next->next){  //ek aur fast->next->next isslie kyuki it is possible ki list sirf 2 size ki ho so in that case we must check it
 
        slow=slow->next;
        fast=fast->next->next;

    }

    return slow;
}


ListNode* merge(ListNode* left,ListNode* right){

    ListNode* dummy=new ListNode(-1);

    ListNode* temp=dummy;

    while(left and right){

        if(left->val<=right->val){
            temp->next=left;
            left=left->next;
        }

        else{

            temp->next=right;
            right=right->next;
        }

        temp=temp->next;
    }

    while(left){
        temp->next=left;
        left=left->next;
        temp=temp->next;
    }

    while(right){
        temp->next=right;
        right=right->next;
        temp=temp->next;
    }

    return dummy->next;  //next isslie kyu first one is -1



}

ListNode* divide(ListNode* head){

     if(head==NULL or head->next==NULL){  //base case
            return head;
        }

        //abh mid nikalo

        ListNode* mid=findMid(head);

        //abh too part me divide

        ListNode* left=head;
        ListNode* right=mid->next;

        mid->next=NULL;

        left=divide(left);

        right=divide(right);

       return merge(left,right);


}


    ListNode* sortList(ListNode* head) {

        

        return divide(head);


        
    }
};
