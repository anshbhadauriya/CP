class SmallestInfiniteSet {
public:
int smallest=1;
set<int>st;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {

        if(!st.empty()){  //set me hmesha smallest counter se chota ele hi hoga too return st ele first
            int ele=*st.begin();
            st.erase(st.begin());
            return ele;
        }


        return smallest++;
        
        
    }
    
    void addBack(int num) {
        if(num<smallest){
            st.insert(num);
        }
    }
};

