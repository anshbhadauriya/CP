class MyHashMap {
public:
//seperate chaining method

vector<vector<pair<int,int>>>mp; //{idx-> { {key1,val1} , {key2,val2} , {key3,vala3}.....} }

int M;

    MyHashMap() {
         M=10000;  //let
        mp.resize(M);
    }

    int getIndex(int key){
    return key%M;
    }
    
    void put(int key, int value) {

        int idx=getIndex(key);

        //check ki already key present hai kya

       auto &chain= mp[idx];

       for(auto &x:chain){
        if(x.first==key){
            x.second=value;
            return;
        }
       }

       //agr nhi present hai too

       chain.push_back({key,value});

    }
    
    int get(int key) {
        
        int idx=getIndex(key);

        auto &chain=mp[idx];

        for(auto &x:chain){
        if(x.first==key){
            return x.second;
        }
       }

       return -1;  //agr key nhi hai


    }
    
    void remove(int key) {
        int idx=getIndex(key);

        auto &chain=mp[idx];

        for(int i=0;i<chain.size();i++){
            if(chain[i].first==key){
                chain.erase(chain.begin()+i);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
