Q1->  class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int minimum=INT_MAX,idx=-1;
        for(int i=0;i<capacity.size();i++){
            if(capacity[i]>=itemSize){

                if(minimum>capacity[i]){
                    minimum=capacity[i];
                
                if(minimum==capacity[i])
                 idx=i;
                }
            }
                
        }
        return idx;
    }
};

Q2->  class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return -1;
        vector<long long>sum(n,0),prod(n,1);

        long  long pref_sum=0;
        long long suff_prod=1;

        
prod[n-1]=1;
        for(int i=n-2;i>=0;i--){
            if(nums[i+1]!=0 and prod[i+1]>LLONG_MAX/nums[i+1]) prod[i]=LLONG_MAX;
            else prod[i]=prod[i+1]*nums[i+1];
        }
  
        for(int i=0;i<nums.size();i++){
            if(pref_sum==prod[i]) return i;

            pref_sum+=nums[i];
        }

        
        return -1;
    }
};

Q3->  class Solution {
public:
    int minOperations(string s) {

        string ideal=s;
        sort(ideal.begin(),ideal.end());

        if(s==ideal) return 0;         

        string temp1=s;

        int n=s.size();

        if(s.size()==2){
            if(s==ideal) return 0;

            else return -1;
        }

        //operation 1

        sort(temp1.begin(),temp1.begin()+(n-1));   

        if(temp1==ideal) return 1;


        string temp2=s;


        sort(temp2.begin()+1,temp2.end());

        if(temp2==ideal) return 1;

        //operation 2


        sort(temp1.begin()+1,temp1.end());


        if(temp1==ideal) return 2;


        sort(temp2.begin(),temp2.begin()+(n-1));

        if(temp2==ideal) return 2;



        //operation 3 -> abh too sort ho hi jaega


        return 3;





    }
};

Q4->

  class Solution {
public:

long long solve(int l,int r,int encCost,int flatCost,vector<int>&prefix){

    int number_of_one=prefix[r]-((l-1>=0)?prefix[l-1]:0);

    int len=r-l+1;

    long long curr_cost=0;
    if(number_of_one==0){
        curr_cost+=flatCost;
        
    }
    else{ 

    curr_cost+=1LL*((len)*(1LL*number_of_one)*encCost);
    
    }

    if(len%2!=0) return curr_cost;

    int mid=l+(r-l)/2;

    long long split = solve(l,mid,encCost,flatCost,prefix)
                    + solve(mid+1,r,encCost,flatCost,prefix);

        return min(curr_cost,split);
}
    long long minCost(string s, int encCost, int flatCost) {
        //s[i]='1'   -> element is sensitive
        //s[i]='0    -> not sensitive

        //string must be partitioned into segments....

        //Initially the entire string forms a single segment

        //1010  ->  length * number of sensitive elements * enCost

        //break into half

        //10,10 ->    4,4  ->  8

        //apporach->   everytime you have to find check if its odd length of even length

        //if odd length then simply add cost

        //if even length break so addd cost and then break into two parts

        vector<int>prefix(s.size(),0);

        int one=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                ++one;
            }
            prefix[i]=one;
        }

        
        

        return solve(0,s.size()-1,encCost,flatCost,prefix);


    }
};
