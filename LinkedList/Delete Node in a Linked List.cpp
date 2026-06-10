class Solution {
public:
/*
the trick is instead of deleting we just disconnect it
 4 -- 5 -- 1 -- 9 and target=5

so first put next value in target

 4 -- 1 -- 1 -- 9

 and now just connect curr too curr->next->next

 4 -- 1 -- 9
*/
    void deleteNode(ListNode* target) {
        target->val=target->next->val;
        target->next=target->next->next;
        
    }
};
