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

optimal apporach->

/*
Now optimal appraoch

step1->
7->13->11->10->1->NULL

7->7'->13->13'->11->11'->10->10'->1->1'->NULL

step2->

connect random pointers

step3->

extract new linked list

TC is O(n)

SC is O(1)

*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        Node* temp=head;

        while(temp){
            Node* save=temp->next;
            temp->next=new Node(temp->val);

            temp->next->next=save;

            temp=temp->next->next;
        }        

        temp=head;


        while(temp){
            if(temp->random==NULL){
                temp->next->random=NULL;
            }
            else temp->next->random=temp->random->next; //jo curr ele ka copy hai uska random hmehsa whi hoga jisko current ele ka random ka next ho

            /*
            for example

            7->7'->13->13'->11->11'->10->10'->1->1'->NULL

            to find 7' random
            check 7 random 
            suppose 7 random is 13 

            so 7' random is 13->next which is 13'

            7'->13'

            */

            temp=temp->next->next;

        }

        //step 3 is extract new LL

        Node* dummy= new Node(-1);

        temp=head;

        Node* res=dummy;

        while(temp){  
            Node* save=temp->next->next;  //save kro next orginal node 
            temp->next->next=NULL; //copy next ko null kro
            res->next=temp->next; //new linked list me copy ko add kro
            temp->next=save; //orignal node ke next me save wala laga do
            temp=temp->next; 
            res=res->next; 
        } 

        return dummy->next;
    }
};
