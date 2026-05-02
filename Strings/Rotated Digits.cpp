class Solution {
public:
    int rotatedDigits(int n) {

        unordered_map<char,char>mp{{'2','5'},{'5','2'},{'6','9'},{'9','6'}};

        int count=0;

        for(int i=1;i<=n;i++){
            string curr=to_string(i);

            bool khatam=false;

        for(int j=0;j<curr.size();j++){
            if(mp.count(curr[j])) curr[j]=mp[curr[j]];
            else if(curr[j]=='3' or curr[j]=='4' or curr[j]=='7'){
                khatam=true;
                break;
            }
        }

        if(khatam) continue;

        int temp=stoi(curr);

        if(temp!=i) count++;

        }

        return count;

        
        
    }
};
