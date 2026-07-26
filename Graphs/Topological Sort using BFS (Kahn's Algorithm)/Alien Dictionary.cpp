/*

alien language 

so alien ki dictionary aur lang hamari lang se diff hai

unke dict ke words hame line se die hai 

unn words ka use krke pata krna hai ki what is the order of letters 

we dont have to return true or false

we just have to return order

so if u notice so ek directed graph ban jaega

aur directed graph me order pta krna ho to uk ki we have to use topo sort




*/
class Solution {
  public:
  
    string findOrder(vector<string> &words) {
        
        int n=words.size(); //it will tell ki kitne words hai
        
        //pehle adj list bana lo
        
        //adj list me alphabet nhi unka number dalna like a ka 0 ba ka 1
        
        vector<vector<int>>adj(26);
        
        vector<int>present(26,0); //it will store ki kon kon se alphabets hai words me
        
        vector<int>indegree(26,0);
        
        //ek bar me 2 string ko compare krna hoga to know order
        
        for(auto &curr:words){
            
            for(auto x:curr) present[x-'a']=1;
        }
        
        for(int i=0;i<n-1;i++){
            
            string &a=words[i];
            string &b=words[i+1];
            
            bool found=false;
            
            for(int j=0;j<min(a.size(),b.size());j++){
                
                if(a[j]!=b[j]){
                    
                    adj[a[j]-'a'].push_back(b[j]-'a');
                    
                    indegree[b[j]-'a']++;
                    
                    found=true;
                    break;
                 
                }
            }
            /*
            words = {"abc", "ab"}
            agr aissa case aajae too return false 
            
            */
            if (!found && a.size() > b.size())  //kabhi longer word pehle aajae smaller word ke 
            return "";
        }
        
       
        
        //abh topo lagao
        
        queue<int>q;
        
        int total=0;  //it will count ki total kitne character hai which will help later
        
        for(int i=0;i<26;i++){
            
            if(present[i] ){
                total++;
                
                if(indegree[i]==0) q.push(i);
            }
        }
        
        string ans="";
        
        while(!q.empty()){
            
            int curr=q.front();
            q.pop();
            
            ans.push_back(char(curr+'a'));
            
            for(auto x:adj[curr]){
                
                indegree[x]--;
                
                if(indegree[x]==0) q.push(x);
            }
        }
        
        if(ans.size()!=total){  //agr ans me sare ele nhi aae mtlb cycle exist 
        
        return "";
        }
        
        return ans;

        
    }
};

/*
Time Complexity = O(N × M + V + E)
Space Complexity = O(V + E)
*/
