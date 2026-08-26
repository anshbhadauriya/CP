class MyCircularDeque {
public:
int *arr;
int front;
int rear;
int max_size;
int sizee=0;
    MyCircularDeque(int k) {

        max_size=k;
        arr= new int[k];

        front=0;
        rear=max_size-1;
        
    }
    
    bool insertFront(int value) {

        if(sizee==max_size) return false;
        
        front=(front-1+max_size)%max_size;

        arr[front]=value;

        sizee++;

        return true;

    }
    
    bool insertLast(int value) {

        if(sizee==max_size) return false;

        rear=(rear+1)%max_size;

        arr[rear]=value;

        sizee++;

        return true;
    }
    
    bool deleteFront() {

        if(sizee==0) return false;

        front=(front+1)%max_size;

        sizee--;

        return true;


    }
    
    bool deleteLast() {

        if(sizee==0) return false;

        rear=(rear-1+max_size)%max_size;

        sizee--;

        return true;
        
    }
    
    int getFront() {

        if(sizee==0) return -1;

        return arr[front];
        
    }
    
    int getRear() {

        if(sizee==0) return -1;

        return arr[rear];
        
    }
    
    bool isEmpty() {

        return sizee==0;
        
    }
    
    bool isFull() {

        return sizee==max_size;
        
    }
};
