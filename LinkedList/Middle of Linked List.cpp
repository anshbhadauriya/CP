class Solution {
public:

/*


| Condition                              | Middle you get|
| ---------------------------------------| --------------|
| fast && fast->next                     | Second middle |
| fast && fast->next && fast->next->next | First middle  |


*/

    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL and fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};
