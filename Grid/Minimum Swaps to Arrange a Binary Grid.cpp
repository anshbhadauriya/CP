class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        //valid if all the cells above the (1,1) diagonal are zeros
        //operation-> 2 adjacent row ko swap kr skte ho
        //count min operations to make it valid

        

        //acsending order me lagana hai kisi trh

        //step1-> count trailing zeros

        int n=grid.size();

        vector<pair<int,int>>result;  //{row,no. trailing zeros}

        for(int i=0;i<n;i++){
            int zeros=0;
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]==1) break;
                zeros++;
            }
            result.push_back({i,zeros});
        
        }

        //kisi tarah aisse order me laao ki ith row should have n-i+1 trailing zeros

     
        int operations=0;
        //kisi tarah minimum required ko lao line se

        for(int i=0;i<n;i++){

            int min_required=n-(i+1);  //i'th row me atleast itne zero too hone hi chaiye

            //abh check kro ki kya kisi row ki paas minimum itne zero hai

            int minimum=INT_MAX,row=-1;

            for(int j=i;j<n;j++){
                auto x=result[j];
                if(x.second>=min_required){
                    row=j;
                   break;
                }
            }

            if(row==-1) return -1;

            while(row>i){
                swap(result[row],result[row-1]);
                operations++;
                row--;
            }


        }

       



        return operations;


       
        

    }
     //note-> paired vector banana was useless 
};