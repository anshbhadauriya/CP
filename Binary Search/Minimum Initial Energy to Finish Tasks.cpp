class Solution {
public:

static bool comperator(vector<int>&a,vector<int>&b){

    return (a[1]-a[0])>(b[1]-b[0]); //so basically jo bhi task actual me hai chota lekin entry ke lie bhot zyda le rha usko pehle ham log lege (greedy)
}
    int minimumEffort(vector<vector<int>>& tasks) {
        
        /*
        
        taks[0]-> itni energy waste hogi 

        task[1]-> itni energy honi chaiye tabhi process hoga


        mtlb jiski bhi sbse badi take[1] hai usse hame start krna h

        so sort as per 2nd ele of vector

        


        */

        sort(tasks.begin(),tasks.end(),comperator);

        int sum=0;

        for(auto x:tasks){
         sum+=x[1]; 
         cout<<x[1]<<" ";
    }

    cout<<endl;

    cout<<"sum is "<<sum<<endl;



        cout<<endl;

        int n=tasks.size();

        int l=0,h=sum;

        int ans=-1;

        while(l<=h){

            int mid=l+(h-l)/2;

            int total_energy=mid;

            bool not_possible=false;

            for(int i=0;i<n;i++){
                int must_have=tasks[i][1];

                int curr_energy=tasks[i][0];

                if(total_energy>=must_have and total_energy>=curr_energy){
                    total_energy-=curr_energy;
                }
                else{
                    not_possible=true;
                }
            }

            if(not_possible){   //energy badao

           l=mid+1;

            }
            else{

                ans=mid;
                h=mid-1;
            }


        }




        return ans;


    }
};
