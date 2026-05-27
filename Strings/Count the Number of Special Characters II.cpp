class Solution {
public:
    int numberOfSpecialChars(string word) {
        /*
        Mine approach worked but its not efficient

        editorial ki approach hai ki har ele ke lowercase ke last occurence aur har ele ke uppercase occurence ko store kro

        so if last occurence of lower ele < first occurence of upper ele so count++

        kyuki larger ele hamesha smaller ke baad hi aane chaiye
        
        so lets try editorial approach as well
        */

        vector<int>last_occ_of_small(26,-1),first_occ_of_bigger(26,-1);


        for(int i=0;i<word.size();i++){

            char curr=word[i];


            if(islower(curr)){

                last_occ_of_small[curr-'a']=i;

            }
            else{

                if(first_occ_of_bigger[curr-'A']==-1) first_occ_of_bigger[curr-'A']=i;
            }
        }

        int count=0;

        for(int i=0;i<26;i++){

            if(last_occ_of_small[i]!=-1 and first_occ_of_bigger[i]!=-1 and first_occ_of_bigger[i]>last_occ_of_small[i]) count++;
        }

        return count;

        
    }
};



My appraoch->

class Solution {
public:
    int numberOfSpecialChars(string word) {

        /*
        
        letter c is special if vo upper case or lowercase dono me aae 

        lekin lowercase pehle aae uppercase se

        so track the lowercase 
        if uppercase came before so that ele is not possible
        
        */


        /*
        
        piche se traverse kro

        pehle impossible wale remove krdo

        impossible vo hoge jo bhi capital pehle aajae

        */


        //remove impossible

        unordered_set<char>st,impossible,ans,smaller;

        int n=word.size();
        for(int i=0;i<n;i++){

            char curr=word[i];
            char curr_smaller=tolower(word[i]);
            char curr_bigger=toupper(word[i]);

            //agr current is smaller lekin usse pehle bigger aachuka ho too impossible

            if(islower(curr) and st.count(curr_bigger)){
                impossible.insert(curr_smaller);
                impossible.insert(curr_bigger);
                continue;
            }

            st.insert(curr);

        }

        for(auto x:impossible) cout<<x<<" ";

        cout<<endl;

        //impossible mil gae abh check normally

        for(auto x:word){

            if(impossible.count(x)) continue;

            char curr_smaller=tolower(x);
            char curr_bigger=toupper(x);

            if(isupper(x) and smaller.count(curr_smaller)){
                ans.insert(x);
                continue;
            }

            smaller.insert(x);

        }

        return ans.size();



       
        
    }
};
