class Solution {
public:

/*
repeatedly take the largest value ≤ num

check how many times it can divide num (lets say n times) so add that value symbol n times in answer string

then do num % value

remember the map value strucutre as there can be smaller number than M,D,C so in to cover all cases we can store pre Symbol values like CM , CD , XC , XL , IX , IV 

*/
    string intToRoman(int num) {


        vector<pair<int,string>> mp = {
    {1000,"M"},
    {900,"CM"},
    {500,"D"},
    {400,"CD"},
    {100,"C"},
    {90,"XC"},
    {50,"L"},
    {40,"XL"},
    {10,"X"},
    {9,"IX"},
    {5,"V"},
    {4,"IV"},
    {1,"I"}
};
    
    string answer="";


    for(int i=0;i<mp.size();i++){  //notice kro ki num hmesha chota hota rhega so one traversal is enough
        int value=mp[i].first;
        string symbol=mp[i].second;

        if(value<=num){
            int t=num/value;

            while(t--) answer+=symbol;

            num=num%value;
        }
        
    }


    return answer;

    /*
    Since there are only 13 values in mp so in worse case 
    TC is O(13)

    SC is O(1), ignoring auxiliary space
    */
        
    }
};
