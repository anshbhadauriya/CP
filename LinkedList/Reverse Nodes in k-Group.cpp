/*

the idea is:

bar bar linked list ko k group me break krke reverse kro

head ko temp mark kro => kth node ko kth mark kro => kth node ke next ko NULL kro => reverse kro

reverse krne ke baad abh temp last me aagya aur kth sbse pehle soo

kth ko head mark krdo agr yeh first time horha kyuki at the end head hi return krna hai 

abh first time kab hai yeh kaise pta chlega?? temp agr head pr hai too mtlb yeh first group hai soo 
if (temp==head)  head=kth (as uk ki reverse krne ke baad head kth first me aajega)

aur jab ek group reverse hojae too uk ki usse baad me dusre group se connect bhi krna hoga when we will do same in next group so uk temp is last node after reversing so mark temp as prev so jab ham next group ko reverse kr lege so uske first node ko prev se connect krna hoga so

prev->next=kth node ( as kth is first node after reversing)

keep doing this 



 */
class Solution {
public:

void reverse(ListNode* head) {  //reverse kro
        ListNode* cur=head;
        ListNode* pre=NULL;
        while(cur!=NULL){
            ListNode* nex=cur->next;
            cur->next=pre;
            pre=cur;
            cur=nex;
        }
    }

    ListNode* kthNode(ListNode* head,int k){  //kth node find kro
        k=k-1; //ek kam isslie kyuki agr k 3 hai too actually head ko 2 bar aage badana hai

        while(head!=NULL and k--){ 
            head=head->next;
        }
        return head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp=head;
        ListNode* prev=NULL;

        while(temp!=NULL){

            ListNode* kth=kthNode(temp,k); //kth node find krdo

            if(kth==NULL){  

                if(prev) prev->next=temp;
                break;
            }

            ListNode* nex=kth->next; //pehle hi next LL ke head ko save krlo (preserve it)

            kth->next=NULL; //kth ka next ko null krdia taki ek segment mil jae pura reverse krne ke lie

            reverse(temp);

            if(temp==head){ //sirf pehli baar hi aissa hoga(1st group)..so it means jo last me return krna hai usko mark krdo
            
            head=kth;
            
            }
            else{   //pichle group ke last ele ko iss group ke first ele se connect kro
            //kth is first ele of the group after reversing

                prev->next=kth;

            }

            prev=temp;  //reverse krne ke baad prev last me hogya hai so mark it as prev  
            //agle group ko reverse krne ke baad jo uska head hoga usse piche group se connect krne ke lie prev kaam aaega soo prev->next = kth ele hojaega agle group me
            temp=nex;

        }
        return head;
    }
};

/*
TC = O(n)
SC = O(1)
*/
