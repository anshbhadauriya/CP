class Solution {
public:
/*

tricky ques..

iss question me we have to keep track of ele which has highest frequency

kyuki agr kabhi koi aur ele aaya too ham max freq ele ke alawa bakio ko hataege

so basically current_window_length-max_freq krke pata chlega kitne element hai subarray me jo max freq me nhi aate hai.. hame ussi elements ko remove krna hai

and keep track of maximum window


*/
    int characterReplacement(string s, int k) {

        int l=0,h=0,maximum=0,max_freq_ele=0;

        unordered_map<char,int>mp;

        while(h<s.size()){

            mp[s[h]]++;

            max_freq_ele=max(max_freq_ele,mp[s[h]]);


            while((h-l+1)-max_freq_ele>k and l<=h){   //(h-l+1)-max_freq_ele means ki jo ele max freq na ho..and always remember ki dont make a variable for window size bcs window is changing its length so if you make a variable for window length it will be of fixed size

                mp[s[l]]--;
                
                l++;
            }

            maximum=max(maximum,h-l+1);
            
            h++;

        }

        return maximum;
        
    }
};
