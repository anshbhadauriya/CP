//take pop skip

Same as subsets question only difference is :

size of subset is given

maximum value is given manually


https://www.youtube.com/watch?v=QQ9Tn2i269I&list=PLpIkg8OmuX-KJPC18SGiRUzJQAYo839ox&index=7

class Solution {
public:
vector<vector<int>>result;
void solve(int idx,int n,int k,vector<int>&temp){
    if(temp.size()==k){
        result.push_back(temp);
        return;
    }
        if(idx==n+1){
        return;
    }

        temp.push_back(idx);
        solve(idx+1,n,k,temp);
        temp.pop_back();
        solve(idx+1,n,k,temp);
    
}
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        solve(1,n,k,temp);
        return result;
    }
};
