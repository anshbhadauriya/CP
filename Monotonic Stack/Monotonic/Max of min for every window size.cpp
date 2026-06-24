GO DOWN FOR OPTIMIZED !!
  
class Solution {
  public:
  /*
  Idea of brute force is
  
  sare subarray generate kro aur unka minimum track kro
  
  jo bhi subrray ka size ho usska maximum ek vector me store kro
  */
    vector<int> maxOfMins(vector<int>& arr) {
        
        
        //brute force
        
        int n=arr.size();
        
        vector<int>temp(n+1,0);  //it will store maximum of minimum of all subarray length
        
        for(int i=0;i<n;i++){
            int minimum=INT_MAX;
            for(int j=i;j<n;j++){
                
                minimum=min(minimum,arr[j]);
                
                int size=j-i+1;
                
                if(temp[size]==0){
                    temp[size]=minimum;
                }
                else temp[size]=max(temp[size],minimum);
                
            }
        }
        
        temp.erase(temp.begin());
        
        return temp;
        
    }
};

Slight better but still O(n^2)

/*
The idea of optimal solution is:

Har ele se pucho ki vo kis kis window size ke lie minimum hai..aur jis bhi window size
ke lie minimum hai usse store kro vector me 

For example:

[10, 20, 30, 50, 10, 70, 30]

yha pr 20 se pucho vo kis kis window size ke lie minimum hai

20
20,30
20,30,50

total 3 different size windows -> 1 2 3

same abh 30 se pucho->

30
30,50

total 2 different size window ke lie-> 1 2 


so har window size ke minimum ko track krte rho aur unka maximum nikalo

so har ele ka next smaller ele aur prev smaller ele find krna hai mtlb

so curr ele is smaller with all ele between

NSE  <-->  PSE


*/

class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        
        int n=arr.size();
        
        stack<int>st,st2;
        vector<int>nse(n),pse(n);
        vector<int>ans(n,0);
        
        
        //next smaller ele
        // cout<<"nse->  "<<" ";
        for(int i=n-1;i>=0;i--){
            
            while(!st.empty() and arr[i]<=arr[st.top()]){
                st.pop();
            }
            
            if(st.empty()){
                nse[i]=n;
            }
            else nse[i]=st.top();
            
            
            st.push(i);
            
            // cout<<nse[i]<<" ";
            
        }
        
        // cout<<endl;
        
        //prev smaller ele
        
        // cout<<"pse-> "<<" ";
        
        for(int i=0;i<n;i++){
            
            while(!st2.empty() and arr[i]<=arr[st2.top()]) st2.pop();
            
            if(st2.empty()) pse[i]=-1;
            else pse[i]=st2.top();
            
            
            st2.push(i);
            // cout<<pse[i]<<" ";
            
        }
        
        // cout<<endl;
        
        
        //abh dekho curr ele kitni window size ke ele's ke lie minimum hai
        
        for(int i=0;i<n;i++){
            
            int a=nse[i];
            int b=pse[i];
            
            int diff=a-b-1;   //itni window sizes ke lie curr ele is minimum
            
            /*
            
            Appraoch is right lekin tum har idx me value rkh rhe ho too tc will
            be O(n^2)
            
             
             */
            
            for(int size=1;size<=diff;size++){
                ans[size-1]=max(ans[size-1],arr[i]);
            }
            
            
        }
        
        return ans;
        
        
        
        
    }
};

OPTIMIZED O(n) ->


/*
The idea of optimal solution is:

Har ele se pucho ki vo kis kis window size ke lie minimum hai..aur jis bhi window size
ke lie minimum hai usse store kro vector me 

For example:

[10, 20, 30, 50, 10, 70, 30]

yha pr 20 se pucho vo kis kis window size ke lie minimum hai

20
20,30
20,30,50

total 3 different size windows -> 1 2 3

same abh 30 se pucho->

30
30,50

total 2 different size window ke lie-> 1 2 


so har window size ke minimum ko track krte rho aur unka maximum nikalo

so har ele ka next smaller ele aur prev smaller ele find krna hai mtlb

so curr ele is smaller with all ele between

NSE  <-->  PSE


*/

class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        
        int n=arr.size();
        
        stack<int>st,st2;
        vector<int>nse(n),pse(n);
        vector<int>ans(n,0);
        
        
        //next smaller ele
        // cout<<"nse->  "<<" ";
        for(int i=n-1;i>=0;i--){
            
            while(!st.empty() and arr[i]<=arr[st.top()]){
                st.pop();
            }
            
            if(st.empty()){
                nse[i]=n;
            }
            else nse[i]=st.top();
            
            
            st.push(i);
            
            // cout<<nse[i]<<" ";
            
        }
        
        // cout<<endl;
        
        //prev smaller ele
        
        // cout<<"pse-> "<<" ";
        
        for(int i=0;i<n;i++){
            
            while(!st2.empty() and arr[i]<=arr[st2.top()]) st2.pop();
            
            if(st2.empty()) pse[i]=-1;
            else pse[i]=st2.top();
            
            
            st2.push(i);
            // cout<<pse[i]<<" ";
            
        }
        
        // cout<<endl;
        
        
        //abh dekho curr ele kitni window size ke ele's ke lie minimum hai
        
        for(int i=0;i<n;i++){
            
            int a=nse[i];
            int b=pse[i];
            
            int diff=a-b-1;   //itni window sizes ke lie curr ele is minimum
            
            /*
            
           so instead of putting every ele in each idx just put in max size idx
           
           mtlb agr 2 minimum hai window sized 1 ,2 ,3 ,4 ke lie too instead of putting 
           
           it in 1 ,2 ,3 ,4 just put it in 4 
            
             
             */
            
            ans[diff-1]=max(ans[diff-1],arr[i]);
            
            
        }
        
        int maxii=0;
        
        for(int i=n-1;i>=0;i--){
            maxii=max(maxii,ans[i]);
            ans[i]=maxii;
        }
        
        return ans;
        
        
        
        
    }
};
