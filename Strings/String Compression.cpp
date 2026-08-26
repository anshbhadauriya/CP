class Solution {
public:
    int compress(vector<char>& chars) {

        int count=1,write=0;

        for(int i=0;i<chars.size();i++){

            if(i+1<chars.size() and chars[i]==chars[i+1]) count++;

            else{

                chars[write]=chars[i];
                write++;

                if(count>1){

                    string num=to_string(count);

                    for(auto x:num){
                        chars[write]=x;
                        write++;
                    }
                }

                count=1;
            }
        }

        return write;


        
    }
};
