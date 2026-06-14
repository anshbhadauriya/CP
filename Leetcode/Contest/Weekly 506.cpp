class Solution {
public:
    bool checkGoodInteger(int n) {

        string str=to_string(n);

        int squaresum=0,digitsum=0;

        for(int i=0;i<str.size();i++){
            digitsum+=str[i]-'0';
            squaresum+=(str[i]-'0')*(str[i]-'0');
        }

        if(squaresum>=50+digitsum) return true;

        return false;
        
    }
};

class Solution {
public:

    /*

    if subarray contain 1 ele so freq baalnced

    if >=2 ele then every ele with max freq must comes twice as distinct values

    return man length subarray

    mtlb agr mp ka size ek hai soo freq balanced

    if >=2 so majority ele 
    
    */
    int getLength(vector<int>& nums) {

        int maximum=0,l=0,h=0,n=nums.size();

        


        for(int i=0;i<n;i++){

            unordered_map<int,int>count;
            unordered_map<int,int>freq_of_freq;

            int temp_max=0;

            for(int j=i;j<n;j++){
                int num=nums[j];

                if(count[num]>0)
                    freq_of_freq[count[num]]--;

                count[num]++;
                freq_of_freq[count[num]]++;

                temp_max=max(temp_max,count[num]);

                if(count.size()==1){

                    maximum=max(maximum,j-i+1);
                }

                else if(count.size()>=2){

                    int count_of_max=freq_of_freq[temp_max];
                    int count_of_other=count.size()-count_of_max;

                    bool hasother=false;

                    if(count_of_other>0) hasother=true;
                    else hasother=false;

                    if(hasother and temp_max%2==0){

                        if(freq_of_freq[temp_max/2]==count_of_other){
                            maximum=max(maximum,j-i+1);
                        }
                    }
                }
            }
        }

        return maximum;
        
    }
};

class Solution {
public:

/*
kisi device se agr smallest hataoge so it becomes second smallest

so hme judge second rating ke basis me krna chaiye

sender's new rating = second min

reciever's new rating = min(first min of its own device, first min of senders)

jis bhi device ka second min is greater uss device ka first min smallest ko bhejdo 

*/
    long long maxRatings(vector<vector<int>>& units) {

        vector<pair<int,int>>ratings;

        int n=units.size();

        for(int i=0;i<n;i++){

            int first_minimum=INT_MAX,second_minimum=INT_MAX;

            for(auto x:units[i]){

                if(x<first_minimum){
                    second_minimum=first_minimum;
                    first_minimum=x;
                }
                else if(x<second_minimum){
                    second_minimum=x;
                }
            }


            ratings.push_back({second_minimum,first_minimum});

        }

        sort(ratings.rbegin(),ratings.rend());

        long long sum=0;

        int senders_min=INT_MAX;

        for(int i=0;i<n;i++){

            int first_minimum=ratings[i].second;
            int second_minimum=ratings[i].first;


            if(i==n-1){

                if(second_minimum==INT_MAX){ sum+=units[i][0]; continue; }
                sum+=min(first_minimum,senders_min);
                continue;
            }



            sum+=(second_minimum==INT_MAX)?units[i][0]: second_minimum;
            senders_min=min(senders_min,first_minimum);


        }

        return sum;


        
    }
};
