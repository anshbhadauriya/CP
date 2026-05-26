class Solution {
public:

void merge(int l,int mid,int r,vector<int>&nums){

    int left=l;

    int right=mid+1;

    vector<int>temp;

    while(left<=mid and right<=r){

        if(nums[left]<=nums[right]){
            temp.push_back(nums[left]);
            left++;
        }
        else{

            temp.push_back(nums[right]);
            right++;
        }
    }


    //abh bache hue ele

    while(left<=mid){
        temp.push_back(nums[left]);
        left++;
    }

    while(right<=r){
        temp.push_back(nums[right]);
        right++;
    }

    int a=0;
    for(int i=l;i<=r;i++){   //current temporary vector ki saari value nums me uske positon l to r me daalo 

        nums[i]=temp[a];
        a++;
    }

}

void divide(int l,int r,vector<int>&nums){


    if(l>=r) return;

    int mid=l+(r-l)/2;

    divide(l,mid,nums);

    divide(mid+1,r,nums);

    merge(l,mid,r,nums);
}
    vector<int> sortArray(vector<int>& nums) {
        /*
        
        Find mid 

        break in 2 parts

        keep doing these 2 things 

        then merge
        
        */

        divide(0,nums.size()-1,nums);


        return nums;

        
    }
};