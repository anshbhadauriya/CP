class Solution {
public:
/*
dekho krna hai yeh ki ham hashmap ko aisse treat krege ki:

we will use hashamp as a window

if(mp[curr] >0) mtlb abhi hamari target string find nhi hui

if(mp[curr]<=0) it means ki vo window me ele aa chuka 

so initially ham target substring ko  map me dalege 

aur fir s me traverse krege aur check krege ki kya curr ele map me hai..agr hai too count++ kro 
bcs we found a ele and decrease its freq by 1 

so count kabhi bhi target ke size ka hojae too capture its size and its starting idx (as required) and try to shrink window from left

kyuki hame minimum window chaiye soo target find krne ke baad window ka length increase krna doesnt make sense

aur jab piche se shrink kr rhe ho mtlb vo character are no longer part of window so add them back in pending it means we still need to find those ele to remove them

so overall map me kisi ki freq <0 hai soo those ele are in our window

if freq>0 so we still need to find them

aur yeh bhi notice kro ki jo ele target me nhi hai aur jo s me hai unki freq kabhi positive hogi hi nhi kyuki when they will come in window there freq-- and when they get removed from window so freq++
so they will always balance themselves

so issi wjh se iss jab ham target ele ki freq++ krdete hai

so when we find them there freq will get dercrease 

*/
    string minWindow(string s, string t) {
      int n=s.size(),minimum=INT_MAX,start_idx=-1,h=0,l=0;

      int count=0; //count will track how many ele we already found

      unordered_map<char,int>mp; //you can use vector bcs alphabets too sirf 26 tk ho skte hai

      for(auto x:t) mp[x]++;

      while(h<n){

        if(mp[s[h]]>0) count++;   //it was in pending now we found target so count++

        mp[s[h]]--;

        while(count==t.size()){

            if(h-l+1<minimum){
                minimum=h-l+1;
                start_idx=l;
            }

            mp[s[l]]++;

            if(mp[s[l]]>0){ //window se remove hogae vps pending ne aagae so decrease count
            count--;
            }
            l++;
        }

        h++;
      }

      if(start_idx==-1) return "";

      return s.substr(start_idx,minimum);

      /*
      TC O(n+m)
      Sc O(n)
      */


    }
};
