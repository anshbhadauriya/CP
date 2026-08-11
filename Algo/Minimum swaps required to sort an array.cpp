//mergesort + countinversion
#include<bits/stdc++.h>

using namespace std;
int cnt=0;
void merge(int l,int mid,int h,vector<int>&arr){

    vector<int>temp;

    int i=l;
    int j=mid+1;

    while(i<=mid and j<=h){

        if(arr[i]<=arr[j]){  //we know ki i idx is before j here (i<j) so we can say ki agr arr[j]>arr[i] soo this ele is needed to fix and this is inversion so just count ele before j and we will get ki kitne index piche krna hai isse 
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);

             // all remaining elements in left half
            // are greater than arr[j]
            cnt+= mid-i+1;
            j++;
            
        }
    }

    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }

    while(j<=h){
        temp.push_back(arr[j]);
        j++;
    }

    int x=0;
    for(int k=l;k<=h;k++){
        arr[k]=temp[x];
        x++;
    }
} 

void mergeSort(int l,int h,vector<int>&arr){

    if(l>=h) return;
    
    int mid=l+(h-l)/2;

    mergeSort(l,mid,arr);
    mergeSort(mid+1,h,arr);

    merge(l,mid,h,arr);

}

int main(){

    vector<int>arr={5,4,3,1,6,2,7};

    mergeSort(0,arr.size()-1,arr);

    cout<<cnt;
    
    return 0;
}
