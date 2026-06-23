/*
insert krte time check kro ki pehla insertion hai kya..if yes so set back=0 front=0
else back++ and insert

remove krte time check kro ki front==back hai kya if yes so mtlb
queue empty hogya hai and set front and back to initial -1
else just plus front 
*/

class myQueue {

  public:
  int *arr;
  
  int front,back;
  
  int size;
  
  int count=0;
  
    myQueue(int n) {
        // Define Data Structures
        
        arr= new int[n];
        front=-1;
        back=-1;
        size=n;
    }

    bool isEmpty() {
        if(count==0) return true;
        
        return false;
    }

    bool isFull() {
        // check if the queue is full
        
        return count==size;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        
        
        if(front==-1){
            front=0;
            back=0;
        }
        else{
            back++;
        }
        arr[back]=x;
        count++;
    }

    void dequeue() {
        // Removes the front element of the queue.
        
        
        if(front==-1) return;
        
        if(front==back){
            front=-1;
            back=-1;
        }
        else{
            
            front++;
        }
        
        count--;
        
        
        
        
    }

    int getFront() {
        
        if(front==-1) return -1;
        
        return arr[front];
    }

    int getRear() {
        // Return the last element of queue
        
        if(back==-1) return -1;
        
        return arr[back];
    }
};
