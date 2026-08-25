class Node {
public:
    string data;
    Node* next;
    Node* prev;

    Node(string val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class BrowserHistory {
public:
    Node* dummy;

    BrowserHistory(string homepage) {
         dummy= new Node(homepage);
         

        
    }
    
    void visit(string url) {
        Node* newNode=new Node(url);
        dummy->next=newNode;
        newNode->prev=dummy;
        dummy=newNode;
        
    }
    
    string back(int steps) {

        while(steps-- and dummy->prev){
            //if(dummy==head) return dummy->data;
            dummy=dummy->prev;
        }

        return dummy->data;
        
    }
    
    string forward(int steps) {

        while(steps-- and dummy->next){
            dummy=dummy->next;
        }

        return dummy->data;
        
    }
};
