/*
Brute force-> u can do with vector..jo bhi ele me operations kroge usko uski position se hata kr back me laga do 
isse LRU hamesha front me maintain rhega

but the things is ki tum agr har bar delete kroge bich se ya kisi position se too uski tc O(n) hogi har bar which is not good

so ek aissa data structure use kro jo bich ke elements ko hata de O(1) me...so this can be done by doubly linked list

lekin agr kisi random ele ko linked list se hatana hai too pehle uss ele tk too jana pdega traverse krke so it will again cost O(n) so we will store ele's address in map so it will look like value->address

so agr koi bhi ele remove krna ho too just get its address via hashmap and remove that ele

aur haan har new ele ko iss bar shuru me dalege back me nhi kyuki last me dalege too pura traverse krke last tk jana pdega

*/
class LRUCache {
public:
list<int>dll;//it contains all keys (cpp ka stl hai which behaves as doubly linked list)
unordered_map<int, pair<list<int>::iterator, int>> mp; //key->(list_node,value)
    int n;
    LRUCache(int capacity) {
        n=capacity;
    }
    
    int get(int key) {

        if(mp.count(key)){

            auto address=mp[key].first;
            int val=mp[key].second;

            dll.erase(address);
            dll.push_front(key);
            mp[key].first=dll.begin();

            return val;
        }

        return -1;


        
    }
    
    void put(int key, int value) {

        if(mp.count(key)){  //pehle check kro ki already exist kr rhi key ya nhi

            auto address=mp[key].first;

            dll.erase(address);

            dll.push_front(key);

            mp[key].first=dll.begin();
            mp[key].second=value;

        }
        else{  //agr key nhi hai

        if(dll.size() == n){  //too pehle check kro ki capacity too nhi reach hogai
        int lru = dll.back();
        dll.pop_back();
        mp.erase(lru);
        }

            dll.push_front(key);

            mp[key]={dll.begin(),value};
        }
        
    }
};
