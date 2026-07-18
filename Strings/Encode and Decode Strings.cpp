class Solution {
  public:
    string encode(vector<string>& arr) {
        string encoded_string="";
        
        for(auto curr:arr){
            
            int size=curr.size();
            
            string temp="";
            temp+=to_string(size);
            temp+="/:";
            
            temp+=curr;
            
            encoded_string+=temp;
        }
        
        //cout<<encoded_string;
        
        return encoded_string;
    }

    vector<string> decode(string& s) {
        
        vector<string>ans;
        
        int i=0;
        while(i<s.size()){
            //pta kro size string ka pehle
            
            int j=i;
            
            while(s[j]!='/'){
                j++;
            }
            
            int size=stoi(s.substr(i,(j-1)-i+1));
            
            //uk j pr '/' hai so j+2 se string shuru hai
            
            string temp=s.substr(j+2,size);
            
            ans.push_back(temp);
            
            i=(j+2)+size;  //skip /: then string 
        }
        
        return ans;
        
    }
};
