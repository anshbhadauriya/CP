class MinStack {
public:
stack<pair<int,int>>st;  //val , min
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()){
            st.push({value,value});
        }
        else{
            st.push({value,min(st.top().second,value)});
        }
    }
    
    void pop() {

        st.pop();
        
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/*
TC-> O(1)
SC-> O(n) as required
 */
