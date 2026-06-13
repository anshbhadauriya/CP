/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

/*

original linked list node address maps ->  copy linked list node address

isse yeh hoga ki tum jab real linked list me traverse kroge so you can check ki original linked list ki random kon hai so jo bhi random ho uska address se copied address nikal aaega hashmap se

so current copy node ->random = mp[original->random]

TC is O(n)

SC is O(n)
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
       unordered_map<Node*,Node*>mp;

       Node* temp=head;

       Node* dummy=new Node(-1);

       Node* res=dummy;

       while(temp){

        res->next=new Node(temp->val);

        mp[temp]=res->next;

        temp=temp->next;

        res=res->next;

       }

       temp=head;

       res=dummy->next;

       while(temp){

        res->random=mp[temp->random];

        res=res->next;

        temp=temp->next;

       }

       return dummy->next;

        
    }
};
