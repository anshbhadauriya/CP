#include <bits/stdc++.h>
using namespace std;

int main() {
	//N friends ->  ith friend -> color C[i]
	//opposite color --> color changes
	//color changes->jolt++
	//find minimum jolt
	
	//same number no jolt
	
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    
	    set<int>nums;
	    for(int i=0;i<n;i++){
	        int x;
	        cin>>x;
	        nums.insert(x);
	    }
	    
	    cout<<nums.size()<<endl;
	}
	return 0;

}

#include <bits/stdc++.h>
using namespace std;

int main() {
	
	
	//perform operations until s.size()>1 
	//operation-> choose two ele score+=max(x,y)
	//if X AND Y exist in the set so skip else push
	
	
	//you have to try ki set me waps ele nhi dalna pdeee
	
	//so try to always choose those elements who AND is present in set
	
	//choose 
	
	
	int t;
	
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    
	    set<int>st;
	    
	    for(int i=0;i<=n;i++){
	        
	        st.insert(i);
	    }
	    int score=0;
	    while(st.size()>1){
	        int largest=*st.rbegin();
	        auto it = st.rbegin();
            it++;
            int second_largest = *it;
	        int andd=largest & second_largest;
	        st.erase(largest);
	        st.erase(second_largest);
	        
	        if(st.count(andd)){
	            score+=largest;
	        }
	        else{
	            st.insert(largest);
	        }
	        
	        largest-=2;
	        second_largest-=2;
	    }
	    
	    
	    
	    cout<<score<<endl;
	    
	    
	}
	return 0;
	
}


#include <bits/stdc++.h>
using namespace std;

int main() {


   //N FRIENDS -> Baloon smash
   
   
   int t;
   cin>>t;
   
   while(t--){
       
       int n;
       cin>>n;
       vector<int>nums(n);
       for(int i=0;i<n;i++) cin>>nums[i];
       
       vector<int>limit(n,0),result(n,0);
       
       int sum=0;
       for(int i=0;i<n;i++){
           limit[i]+=sum;
           result[i]=limit[i];
           if(result[i]>=nums[i]){
               result[i]=nums[i];
               continue;
           }
             
           sum+=1;
           
       }
       for(auto x:result) cout<<x<<" ";
       
       cout<<endl;
   }

}



