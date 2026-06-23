class myStack {
  public:
  
  int *arr;
  int top;
  int size;
  
    myStack(int n) {
        // Define Data Structures
        arr =  new int[n];
        top=-1;
        size=n;
        
    }

    bool isEmpty() {
        // check if the stack is empty
        
        if(top==-1) return true;
        
        return false;
    }

    bool isFull() {
        // check if the stack is full
        
        if(top==size-1) return true;
        
        return false;
    }

    void push(int x) {
        // inserts x at the top of the stack
        ++top;
        arr[top]=x;
        
    }

    void pop() {
        // removes an element from the top of the stack
   if(top!=-1)     
        top--;
        
    }

    int peek() {
        // Returns the top element of the stack
        if(top==-1) return -1;
        return arr[top];
        
    }
};
