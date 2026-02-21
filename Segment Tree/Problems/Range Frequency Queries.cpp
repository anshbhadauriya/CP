Correct but MLE->

class RangeFreqQuery {
public:
int n;
unordered_map<int, unordered_map<int,int>> seg;
    RangeFreqQuery(vector<int>& arr) {
         n=arr.size();
        build(0,0,n-1,arr);
    }

    void build(int ind,int low,int high,vector<int>& arr){
        if(low == high){
            seg[ind][arr[low]]++;
            return;
        }

        int mid = (low + high) / 2;

        build(2*ind+1,low,mid,arr);
        build(2*ind+2,mid+1,high,arr);
        
        
        unordered_map<int,int> map = seg[2*ind+1];

        for(auto &it : seg[2*ind+2])
        map[it.first] += it.second;

        seg[ind] = map;
    }
    int queryH(int ind, int low, int high, int l, int r, int value){

        if(r < low || high < l){
            return 0;
        }


        if(l <= low && high <= r){
            return seg[ind][value];
        }


        int mid = (low + high) / 2;


        int left = queryH(2*ind+1,low,mid,l,r,value);
        int right = queryH(2*ind+2,mid+1,high,l,r,value);
        
        return left + right;;
    }

    int query(int left, int right, int value) {
        return queryH(0,0,n-1,left,right,value);
    }
};

Slight Optimized that works->


  class RangeFreqQuery {
public:
int n;
unordered_map<int, unordered_map<int,int>> seg;
    RangeFreqQuery(vector<int>& arr) {
         n=arr.size();
        build(0,0,n-1,arr);
    }

    void build(int ind,int low,int high,vector<int>& arr){
        if(low == high){
            seg[ind][arr[low]]++;
            return;
        }

        int mid = (low + high) / 2;

        build(2*ind+1,low,mid,arr);
        build(2*ind+2,mid+1,high,arr);
        
        
        unordered_map<int,int> map = seg[2*ind+1];

        for(auto &it : seg[2*ind+2])
        map[it.first] += it.second;

        seg[ind] = map;
    }
    int queryH(int ind, int low, int high, int l, int r, int value){

        if(r < low || high < l){
            return 0;
        }


        if(l <= low && high <= r){
            return seg[ind][value];
        }


        int mid = (low + high) / 2;


        int left = queryH(2*ind+1,low,mid,l,r,value);
        int right = queryH(2*ind+2,mid+1,high,l,r,value);
        
        return left + right;;
    }

    int query(int left, int right, int value) {
        return queryH(0,0,n-1,left,right,value);
    }
};


