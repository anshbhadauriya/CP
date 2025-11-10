#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int>nums(n);
        for(int i=0;i<n;i++) {
            cin>>nums[i];
        }
        
        sort(nums.begin(),nums.end());
        
        bool can_win=true;
        for (int i=1;i<n-1;i+=2) {
            if (nums[i]!=nums[i + 1]) {
                can_win=false;
                break;
            }
        }
        
        if(can_win){
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
    
    return 0;
}