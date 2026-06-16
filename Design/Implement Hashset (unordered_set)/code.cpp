class MyHashSet {
public:
vector<vector<int>>st;
int M;

int findIndex(int key){
    return key%M;
}
    MyHashSet() {
        M=15000;
        st.resize(M);
    }
    
    void add(int key) {
        int idx=findIndex(key);

    for(int i=0;i<st[idx].size();i++){  //agr pehle se hai so dont add
        if(st[idx][i]==key) return;
    }
    st[idx].push_back(key);
       

    }
    
    void remove(int key) {

        int idx=findIndex(key);

        //check pehle se hai yaa nhi

        int i=0;

        while(i<st[idx].size()){

            if(st[idx][i]==key) st[idx].erase(st[idx].begin()+i);
            else i++;
        }

    }
    
    bool contains(int key) {

        int idx=findIndex(key);

        for(int i=0;i<st[idx].size();i++){
            if(st[idx][i]==key) return true;
        }

        return false;
        
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */