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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* dummy= new ListNode(-1);

        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode* temp3=dummy;

        int carry=0;

        while(temp1 and temp2){ //add both ll

            int sum=temp1->val+temp2->val+carry;

            int curr=0;

            if(carry>0) carry=0;


            if(sum>9){
                curr=(sum%10);
                
                carry+=1;
            }
            else curr=sum;

            cout<<sum<<endl;

            cout<<"carry is "<<carry<<endl;

            temp3->next=new ListNode(curr);

            
            temp1=temp1->next;
            temp2=temp2->next;
            temp3=temp3->next;


        }

        cout<<"remaining carry is "<<carry<<endl;

        while(temp1){  //if temp1 is remaining 
            int sum=temp1->val+carry;

            int curr=0;

            carry=0;

            if(sum>9){
                curr=sum%10;
                carry+=1;
            }
            else curr=sum;

            temp3->next=new ListNode(curr);

            temp1=temp1->next;
            temp3=temp3->next;

            if(!temp1 and carry>0){
            temp3->next=new ListNode(carry);
        }
        }

        while(temp2){  //if temp2 is remaining
            int sum=temp2->val+carry;

            int curr=0;

            carry=0;

            if(sum>9){
                curr=sum%10;
                carry+=1;
            }
            else curr=sum;

            temp3->next=new ListNode(curr);

            temp2=temp2->next;
            temp3=temp3->next;

            if(!temp2 and carry>0){
            temp3->next=new ListNode(carry);
        }
        }

        if(carry and !temp1 and !temp2){  //if both done but still there is some carry left
            temp3->next=new ListNode(carry);

        }

        

        return dummy->next;

        /*
        TC is O(max(n,m)) jis bhi linked list me zyda node hoge
        SC is O(1)
        */
        
    }
};
