class Solution {
public:
    int beautySum(string s) {
        //beauty= most freq - least freq

        //find number of substring whose beauty is more then zero 

        //then sum that beauty 

        //return total sum

        //keep a track of most frequent ele and least freq ele

        //brute force lagao

        int count=0;

        

        for(int i=0;i<s.size();i++){
            vector<int>freq(26,0);
            for(int k=i;k<s.size();k++){

            int curr=s[k]-'a';

            freq[curr]++;

            int minimum_freq=INT_MAX,maximum_freq=INT_MIN;

            for(int j=0;j<freq.size();j++){
                if(freq[j]<minimum_freq and freq[j]>0){
                    minimum_freq=freq[j];
                }
                if(freq[j]>maximum_freq){
                    maximum_freq=freq[j];
                }
            }

            count+=maximum_freq-minimum_freq;

            }
        }

        return count;
    }
};
