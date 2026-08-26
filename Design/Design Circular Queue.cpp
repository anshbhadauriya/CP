/*
agr queue full hojae
and if front se ele deleted hai so u can insert in front

if front bhi full and rear bhi so queue is full so u cannot insert
*/
class MyCircularQueue {
public:
int *arr;
int front=0,rear=0;
int max_size;
int sizee=0;
    MyCircularQueue(int k) {

        max_size=k;
        arr= new int[k];       
    }
    
    bool enQueue(int value) {
        
        if(sizee==max_size){  //size is full

            return false;
        }

        arr[rear]=value;

        rear=(rear+1)%max_size;

        sizee++;

        return true;

    }
    
    bool deQueue() {

        if(sizee>0){
            front=(front+1)%max_size;
            sizee--;
            return true;
        }

        return false;
        
        
    }
    
    int Front() {

        if(sizee>0) return arr[front];

        return -1;
        
    }
    
    int Rear() {

        if(sizee>0){

            int last_idx=(rear-1)%max_size;  //-1 bcs jab hm log insert kr rhe the tab rear++ kr de rhe the last me so rear always points to next cell where ele need to be inserted

            if(last_idx==-1) last_idx=max_size-1;
            return arr[last_idx];
        }

        return -1;
        
    }
    
    bool isEmpty() {

        if(sizee==0) return true;

        return false;
        
    }
    
    bool isFull() {

        if(sizee==max_size) return true;

        return false;
        
    }
};
