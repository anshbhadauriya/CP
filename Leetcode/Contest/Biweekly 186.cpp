Q1->
class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {

    int n=nums.size();

        int mid=n/2;

        unordered_map<int,int>mp;
        for(auto x:nums) mp[x]++;

        if(mp[nums[mid]]==1) return true;

        return false;
        
    }
};
Q2->

class Solution {
public:

    /*
    
    j>i=k
    
    */
    int maxValidPairSum(vector<int>& nums, int k) {

        int n=nums.size();

        vector<int>suffix(n,0);

        int sum=0;

        int maxii=INT_MIN;

        for(int i=n-1;i>=0;i--){
          maxii=max(maxii,nums[i]);
            suffix[i]=maxii;
        }

      //  for(auto x:suffix) cout<<x<<" ";

        int maximum=INT_MIN;
        for(int i=0;i<n;i++){
            if(i+k>=n) break;
            int a=nums[i];
            int b=suffix[i+k];

            maximum=max(maximum,abs(b+a));
        }

        return maximum;

        

      
        
    }
};

Q3->

/*
choose a ele of 0 and make it 1

choose i<n-1 curr or curr+1 agr 1 hai too dono ko 0 krdo

min operations to make s1 equal to s2


mtlb two 1 ko ek sth 0 kr skte ho

aur one 0 ko 1 kr skte ho

tum kabhi single 1 ko 0 nhi kr skte

observations:

agr same ele s2 me 0 hai aur s1 be 

agr kabhi s1 ke idx me 1 ho aur uske aage piche dono 0 ho aur s2 me vo idx 0 ho too impossible so return -1

agr kabhi

1 0 ko  0 0 me change krna ho

too pehle 1 0 -> 0 0 -> 1 1  so 2 operations


case 2-

agr kabhi 1 1 1 ko 0 0 0 me convert krna ho

1 1 1 -> 0 0 1 -> 0 1 1 -> 0 0 0

so pehle jitne match kr skte ho utna kro

case 3-> 0 1 ko 1 0 krna ho too 


0 1 -> 1 0  3 operations

0 0 -> 1 1  2 operations

1 0 -> 0 1  3 operations

1 1-> 0 0   1 operations

1 1 -> 0 1  2 operations

1 0 -> 0 0  2 operations

0 1 -> 0 0  2 operations


*/
class Solution {
public:
int operations=0;
int n;
void solve(string &s1,string &s2,int i){



    
            if(s1[i]=='0' and s1[i+1]=='1' and s2[i]=='1' and s2[i+1]=='0'){
                s1[i]='1';
                s1[i+1]='0';
                operations+=3;
            }
            else if(s1[i]=='0' and s1[i+1]=='0' and s2[i]=='1' and s2[i+1]=='1'){
                s1[i]='1';
                s1[i+1]='1';
                operations+=2;
            }
            else if(s1[i]=='1' and s1[i+1]=='0' and s2[i]=='0' and s2[i+1]=='1'){
                s1[i]='0';
                s1[i+1]='1';
                operations+=3;
            }
            else if(s1[i]=='1' and s1[i+1]=='1' and s2[i]=='0' and s2[i+1]=='0'){
                s1[i]='0';
                s1[i+1]='0';
                operations+=1;
            }
            else if(s1[i]=='1' and s1[i+1]=='1' and s2[i]=='0' and s2[i+1]=='1'){
                s1[i]='0';
                s1[i+1]='1';
                operations+=2;
            }
            else if(s1[i]=='1' and s1[i+1]=='0' and s2[i]=='0' and s2[i+1]=='0'){
                s1[i]='0';
                s1[i+1]='0';
                operations+=2;
            }
            else if(s1[i]=='0' and s1[i+1]=='1' and s2[i]=='0' and s2[i+1]=='0'){
                s1[i]='0';
                s1[i+1]='0';
                operations+=2;
            }

    
}
    int minOperations(string s1, string s2) {
         n=s1.size();

        for(int i=0;i<n-1;i++){
         if(s1[i]=='1' and s1[i+1]=='1' and s2[i]=='0' and s2[i+1]=='0'){
                s1[i]='0';
                s1[i+1]='0';
                operations+=1;
            }
        }



        for(int i=0;i<n-1;i++){
        solve(s1,s2,i);

        }



cout<<s1<<endl;

for(int i=0;i<n;i++){
if(s1[i]=='0' and s2[i]=='1'){
s1[i]='1'; 
operations++;
}
}

if(s1.size()>1 and s1.back()=='1' and s2.back()=='0'){
    s1[n-1]='0';
    operations+=2;

}

// for(int i=0;i<n-1;i++) solve(s1,s2,i);

cout<<s1<<endl;

if(s1!=s2) return -1;

return operations;
        
    }
};
