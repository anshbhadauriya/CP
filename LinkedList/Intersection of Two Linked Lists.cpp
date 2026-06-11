/*

notice kro ki list A aur list B ki length same ho too sth me start kr dete dono ke pointer aur jidhr bhi meet krte so vo meeting point hojata

but length is different so only thing u need to do is find kiski length zyda hai aur kitne diff se zyda hai 

agr list B ki length A se 2 zyda hai too skip 2 node from B and then start traversing from 3rd in list B and from list A start from 1 so length is same now and whenever they meet so thats intersection point

TC is O(m+n+∣m−n∣+min(m,n)) which is O(m+n)
SC is O(1)

 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode* tempA=headA;
        ListNode* tempB=headB;

        int lengthA=0,lengthB=0;

        //length nikalo

        while(tempA){
            lengthA++;
            tempA=tempA->next;
        }

        while(tempB){
            lengthB++;
            tempB=tempB->next;
        }

        tempA=headA;
        tempB=headB;


        //jiski length jitni zyda ho usse utne hi node skip krdo

        if(lengthA>lengthB){
            int diff=lengthA-lengthB;

            while(diff--) tempA=tempA->next;
        }
        else{
            int diff=lengthB-lengthA;

            while(diff--) tempB=tempB->next;
        }

        //abh jis point pr bhi milege that point is intersection point 
        while(tempA and tempB){
            if(tempA==tempB) return tempA;

            tempA=tempA->next;
            tempB=tempB->next;
        }

        return NULL;
        
    }
};
