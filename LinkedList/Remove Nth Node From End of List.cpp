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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(n==1 and !head->next) return NULL;
        int size=0;

        ListNode* temp=head;

        while(temp){
            ++size;
            temp=temp->next;
            
        }

        cout<<size<<endl;

        int to_delete=(size+1)-n;

        cout<<to_delete<<endl;

        if(to_delete==1) return head->next;

        int curr=1;

        temp=head;

        while(temp){
            if(curr+1==to_delete){
                if(temp->next->next){
                    temp->next=temp->next->next;
                }
                else{

                    temp->next=NULL;

                }
            }

            temp=temp->next;
            curr++;
        }

        return head;

        
        
    }
};
