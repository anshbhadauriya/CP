/*
pehli baar traverse krke prefix sum krdo fir baad me 0'se ke pehle wala ele hi save rkhna
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {

        ListNode* temp=head;

        int sum=0;
        while(temp){

            if(temp->val!=0){
                sum+=temp->val;
                temp->val=sum;
            }
            else sum=0;

            // cout<<temp->val<<" ";

            temp=temp->next;
        }

        temp=head;

        ListNode* save=NULL;

        while(temp){

            if(temp->next and temp->next->val==0){

                if(!save) save=temp;

                ListNode* dummy;
                if(temp->next->next==NULL) dummy=NULL;
                else dummy=temp->next->next;

                // cout<<"inital dummy val is "<<dummy->val<<endl;

                while(dummy and dummy->next->val!=0) dummy=dummy->next;
                // cout<<endl;
                // cout<<dummy->val;
                temp->next=dummy;
                temp=dummy;
                continue;
            }

            temp=temp->next;
        }



        return save;


        
    }
};

/*
Lets goo! Done with optimized version!!!!!!!!!!!

TC-> O(n^2) in worse case
SC-> O(1)
*/
