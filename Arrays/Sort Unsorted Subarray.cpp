class Solution {
  public:
    vector<int> findSubarray(vector<int>& arr) {
        
        int n=arr.size();
        
        int left_fault_ele_idx=-1,right_fault_ele_idx=-1;
        
        //find first fault
        
        for(int i=0;i<n-1;i++){
            
            if(arr[i]>arr[i+1]){
                left_fault_ele_idx=i;
                break;
            }
        }
        
        
        //second fault ele
        for(int i=n-1;i>=1;i--){
            
            if(arr[i]<arr[i-1]){
                right_fault_ele_idx=i;
                break;
            }
        }
        
        if(left_fault_ele_idx==-1 and right_fault_ele_idx==-1) return {0,0};
        
        
        // cout<<"left fault idx "<<left_fault_ele_idx<<endl;
        // cout<<"right fault idx "<<right_fault_ele_idx<<endl;
        
        
        //find min and max between window
        
        int minimum=INT_MAX,maximum=INT_MIN;
        
        for(int i=left_fault_ele_idx;i<=right_fault_ele_idx;i++){
            
            if(arr[i]>maximum){
                maximum=arr[i];
            }
            
            if(arr[i]<minimum){
                minimum=arr[i];
            }
        }
        
        // cout<<"min of window "<<minimum<<endl;
        // cout<<"max of window "<<maximum<<endl;
        
        //check any ele before window is smaller than min of window bcs if its less so that
        //upto that part ele is also part of window
        int extended_l=-1,extended_r=-1;
        for(int i=0;i<left_fault_ele_idx;i++){
            
            if(arr[i]>minimum){
                extended_l=i;
                break;
            }
        }
        
        //same check for right
        
        for(int i=n-1;i>right_fault_ele_idx;i--){
            if(arr[i]<maximum){
                extended_r=i;
                break;
            }
        }
        
        int ans_l=left_fault_ele_idx,ans_r=right_fault_ele_idx;
        
        if(extended_l!=-1){
            ans_l=extended_l;
        }
        
        if(extended_r!=-1){
            ans_r=extended_r;
        }
        
        
        return {ans_l,ans_r};
        
        
        
        
    }
};
