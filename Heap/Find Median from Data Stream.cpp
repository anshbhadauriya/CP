/*
max heap me hmesha max.top() se choti value dalo tabhi max heap me chote ele aaege
else push in min heap

agr odd elements aae too max heap ka size ek zyda hona chaiye to return mid

so kabhi bhi min heap size > max heap size so min heap ke top ko nikalkr max heap me dalo

max heap me 1 hi extra ele aaega 1 se zyda extra aagya too top nikalkr min me dalo


*/

class MedianFinder {
public:
priority_queue<int>left_max_heap;

priority_queue<int,vector<int>,greater<int>>right_min_heap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {

        if(left_max_heap.empty() or num<left_max_heap.top()){
            left_max_heap.push(num);
        }
        else{
            right_min_heap.push(num);
        }

        if(left_max_heap.size()-1>right_min_heap.size()){  //max heap ke ek extra se bhi zyda hogya

        right_min_heap.push(left_max_heap.top());  

        left_max_heap.pop();

        /*
        suppose starting me hi 2 ele aagae jo like 5,4 agr yeh condition na hoti too dono left_max_heap me hi hote
        */

        }
        else if(right_min_heap.size()>left_max_heap.size()){  //max heap me hmesha ek ele zyda rkho

            left_max_heap.push(right_min_heap.top());
            right_min_heap.pop();
        }

        
        
    }
    
    double findMedian() {

        

        if((right_min_heap.size()+left_max_heap.size())%2==0){  //even length

        return (right_min_heap.top()+left_max_heap.top())*1.0/2;

        }
        else{

            return left_max_heap.top();
        }
        
    }
};
/*
Tc-> O(n log n)

Sc-> O(n)
*/
