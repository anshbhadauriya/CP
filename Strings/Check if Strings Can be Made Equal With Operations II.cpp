class Solution {
public:
    bool checkStrings(string s1, string s2) {

        //i j and dist bw them is even so you can swap


        //abcdef
        //cbadef  
        //so basically you can swap odd idx ele with odd idx and even idx with even
        //both string freq of all ele should be same

        //s1 -> even idx-> a c b          s2->  c  b  a
            //  odd idx -> b d a               a d b

            //mtlb agr even ka even me ho aur odd ka odd me tabh chlega

            string even1,even2,odd1,odd2;

            for(int i=0;i<s1.size();i++){
                if(i%2==0){
                    even1.push_back(s1[i]);
                    even2.push_back(s2[i]);
                }
                else{
                    odd1.push_back(s1[i]);
                    odd2.push_back(s2[i]);
                }
            }

            sort(even1.begin(),even1.end());
            sort(even2.begin(),even2.end());

            if(even1!=even2) return false;

            sort(odd1.begin(),odd1.end());
            sort(odd2.begin(),odd2.end());

            if(odd1==odd2) return true;

            return false; 


    }
};
