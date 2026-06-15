class Solution {
public:

/*
Isko bhi minimum window substring ki trh kro

pehle map me daaalo

if(curr ele freq>0) so count++ 
mp[curr]--;

if(count==p.size()) so start idx push in answer


we have to keep decrease the size as size is fixed

soo curr ele andr lo aur back ele ko bahar nikalo


*/
    vector<int> findAnagrams(string s, string p) {

        int n=s.size(),l=0,h=0,count=0;

        vector<int>mp(26,0);

        vector<int>result;

        for(int i=0;i<p.size();i++){
            int curr=p[i]-'a';
            mp[curr]++;
        }

        while(h<n){

            int curr=s[h]-'a';

            if(mp[curr]>0){  //found a target ele
                count++;
            }

            mp[curr]--;

            if(count==p.size()){
                result.push_back(l);
            }

            if(h-l+1>=p.size()){  //shrink too tabhi krege na jab window ka size atleast target k size jittna hp
                int back=s[l]-'a';
                mp[back]++;
                if(mp[back]>0) count--;  //target ele bahar chla gya
                l++;
            }

            h++;
        }


        return result;

        /*
        TC O(n)
        Sc O(26)
        */

        
        
    }
};