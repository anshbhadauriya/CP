class Solution {
public:

vector<vector<int>>dp1;
int countOperations(int l,int h,string &s){  //kitne operations needed to hai to make it palindrome
 
    int temp=0;

    while(l<h){

        if(s[l]!=s[h]) temp++;

        l++;
        h--;
    }

    return temp;
}
long long solve(int idx,int partition,string &s,int k){

    if(idx>=s.size()){
        
        if(partition==k-1) return 0;

        return 1e8;
        
    }
    if(partition==k-1){

        //cout<<"yaha tak sb thik hai "<<endl;
        //abh bachi hui string palindrome honi chaiye
        //cout<<"l is "<<idx<<" and h is "<<s.size()-1<<" "<<endl;
        
            //cout<<"yha pr bhi"<<endl;
         return countOperations(idx,s.size()-1,s); //not possible
    }

    if(dp1[idx][partition]!=-1) return dp1[idx][partition];
    long long ans=1e8;

    for(int i=idx;i<s.size()-1;i++){  //partiton too n-2 tk hi possible ho skte na

        //cout<<s[i]<<" ";
        int check=countOperations(idx,i,s);

        ans=min(ans,check+solve(i+1,partition+1,s,k));
        
    }

    return dp1[idx][partition]=ans;
}
    int palindromePartition(string s, int k) {
        dp1.resize(101,vector<int>(101,-1));
        return solve(0,0,s,k);
    }
};
