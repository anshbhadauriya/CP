class Solution {
public:
    bool isprime(int n){
        if(n<=1){
            return false;
        }
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }

    
    bool completePrime(int num) {
        if(!isprime(num)){
            return false;
        }
        int sum=0;
        string str=to_string(num);
        for(int i=0;i<str.size();i++){
            int curr=str[i]-'0';
            sum=sum*10+curr;
            if(!isprime(sum)){
                return false;
            }
        }
        sum=0;

        for(int i=str.size()-1;i>=0;i--){
            int curr=str[i]-'0';
            string temp=str.substr(i,str.size()-i);
            int curr2=stoi(temp);
            if( !isprime(curr2)){
                return false;
            }
        }

        
        return true;
    }
};
