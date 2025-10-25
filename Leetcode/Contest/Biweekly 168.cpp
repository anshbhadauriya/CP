Q1->
class Solution {
public:
    string lexSmallest(string s) {
        string minimum=s,minimum2=s;
        int idx,idx2;
      for(int i=0;i<s.size();i++){
          string temp=s;
         
          reverse(temp.begin(),temp.begin()+i+1);
          if(temp<minimum){
          minimum=temp;
              idx=i;
          }
      }


        for(int i=s.size()-1;i>=0;i--){
            string temp=s;
           
            reverse(temp.begin()+i,temp.end());
            if(temp<minimum2){
                minimum2=temp;
                idx2=i;
            }
        }
        if(minimum<minimum2){
            reverse(s.begin(),s.begin()+idx+1);
            return s;
        }
        reverse(s.begin()+idx2,s.end());
        return s;
        
        
    }

Q2->

zyda se zyda 9 lagao aange bss!
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
       string total="";
       for(int i=0;i<num;i++){
        int x=min(9,sum);
        total+=x+'0';
        sum=sum-x;
       }
       if(sum>0){
        return "";
       }
       return total;
        
    }
};
};
