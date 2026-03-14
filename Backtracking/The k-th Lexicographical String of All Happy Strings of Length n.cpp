class Solution {
public:
set<string>st;

//we have to find all possible combinations of a,b,c  and no alternating same

//after that sort the vector of strings then reurn kth 


//push a
//pop 
//push b
//pop
//push c
//pop

void solve(int n,string &curr){

    if(curr.size()==n){
        st.insert(curr);
        return;
    }

    bool a=false,b=false,c=false;

    if(curr.empty() or curr.back()!='a'){

        a=true;
    curr.push_back('a');
    }
    
    if(a)
    solve(n,curr);

    if(curr.size()>0 and a)
    curr.pop_back();

    if(curr.empty() or curr.back()!='b'){
    b=true;
    curr.push_back('b');
}
    if(b)
    solve(n,curr);

    if(curr.size()>0 and b)
    curr.pop_back();

    if(curr.empty() or curr.back()!='c'){

        c=true;
    curr.push_back('c');

    }

    if(c)
    solve(n,curr);

    if(curr.size()>0 and c)
    curr.pop_back();

}

    string getHappyString(int n, int k) {
        string curr;

        solve(n,curr);
        
        int count=0;

        for(auto x:st){

            count+=1;
            if(count==k){
                return x;
            }
            
        }

    return "";
        
    }
};
