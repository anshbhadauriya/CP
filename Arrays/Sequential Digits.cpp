/*
012
123
234
345
456
567
678
789


1234
2345
3456
4567
5678
6789

%10==0 

12345
23456
34567
45678
56789




*/
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {

        vector<int>initial={12,123,1234,12345,123456,1234567,12345678,123456789};
        vector<int>increase={11,111,1111,11111,111111,1111111,11111111,111111111};

        int i=0;

        vector<int>result;

        while(i<initial.size()){

            int start=initial[i];
            

            while(start%10!=0 and start<=high){
                if(start>=low)
                result.push_back(start);
                // cout<<start<<" ";
                start+=increase[i];
            }

            i++;
        }

        return result;
        
    }
};
