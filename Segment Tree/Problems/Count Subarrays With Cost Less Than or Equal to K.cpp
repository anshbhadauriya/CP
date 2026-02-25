class Solution {
public:
using ll = long long;
int n;
vector<pair<ll,ll>>seg;  //max,min
void build(int i,int l,int r,vector<int>&nums){
    if(l==r){
        seg[i]={nums[l],nums[l]};
        return;
    }

    int mid=l+(r-l)/2;
    build(2*i+1,l,mid,nums);
    build(2*i+2,mid+1,r,nums);

    int a=max(seg[2*i+1].first,seg[2*i+2].first);    //max
    int b=min(seg[2*i+1].second,seg[2*i+2].second);  //min

    seg[i]={a,b};

}

 pair<ll, ll> query(int i,int l,int r,int st,int end){
        if(r<st or l>end) return {LLONG_MIN, LLONG_MAX}; 
        if(l>=st and r<=end) return seg[i];

        int mid=l+(r-l)/2;

        pair<ll, ll> lp = query(2*i+1, l, mid, st, end);
        pair<ll, ll> rp = query(2*i+2, mid+1, r, st, end);


        return {max(lp.first, rp.first), min(lp.second, rp.second)};
}

    long long countSubarrays(vector<int>& nums, long long k) {
        int n=nums.size();
        seg.resize(4*n);
        build(0,0,n-1,nums);

        ll count=0;

        int l=0,h=0;
        while(h<n){
            auto p=query(0,0,n-1,l,h);

            ll cost=(p.first-p.second)*(h-l+1);

            while(cost>k){
                l++;
                auto p=query(0,0,n-1,l,h);
                cost=(p.first-p.second)*(h-l+1);
            }
            count+=(h-l+1);
            h++;
        }
        return count;
    }
};
