class Solution {
public:
/*
so intution is ki smallest integer chaiye too hame num ko ascending order me banana pdega

kyuki suppose hame 3 5 4 2 yeh number mile hai aur hame smallest possible combination banana 
hai iska too ascending order me krna pdega  which is  2 3 4 5

so agr kabhi bhi descening order bne too pop if k is left

*/
    string removeKdigits(string num, int k) {

        string st="";

        for(auto curr:num){

            while(!st.empty() and st.back()>curr and k){  //remove ele greater than curr 
                st.pop_back();
                k--;
            }

            st.push_back(curr);

        }

       // cout<<st<<endl;

        while(k and !st.empty()){
            st.pop_back();
            k--;
        }

        

        while(st.size()>1 and st.front()=='0') st.erase(st.begin());

        if(st.empty()) return "0";
        return st; 


        
    }
};
