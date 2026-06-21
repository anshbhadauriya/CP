class Solution {
public:
    int maxDistance(string moves) {

       

     

        int x2=0,y2=0,ok=0;

        for(auto x:moves){

            if(x=='_'){
                ok++;
            }

            if(x=='U'){
                y2++;
            }
            if(x=='D'){
                y2--;
            }
            if(x=='L') x2--;

            if(x=='R') x2++;

            
        }
        cout<<x2<<" "<<y2;

        return abs(x2)+abs(y2)+ok;
        

        

        
        
    }
};

class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {

        long long count=0;
        for(int i=0;i<nums.size();i++){
            long long sum=0;
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];

                if(sum%10==x){
                long long temp=sum;

                    while(temp>=10){
                        temp=temp/10;
                    }

                    if(temp==x) count++;
            }
        }
        }
        return count;
        
    }
};
