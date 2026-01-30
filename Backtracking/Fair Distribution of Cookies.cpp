class Solution {
public:
int maximum=-1;
int result=INT_MAX;
void solve(int idx,vector<int>&cookies,vector<int>&temp){

    if(idx>=cookies.size()){
        int maximum=*max_element(temp.begin(),temp.end());
        result=min(result,maximum);
        return;
    }
    
    for(int i=0;i<temp.size();i++){
        temp[i]+=cookies[idx];  //kaam
        solve(idx+1,cookies,temp);  //call
        temp[i]-=cookies[idx];   //undo (backtracking)
    }
}
    int distributeCookies(vector<int>& cookies, int k) {

      vector<int>temp(k,0);
      solve(0,cookies,temp);

      return result;

    }
};
