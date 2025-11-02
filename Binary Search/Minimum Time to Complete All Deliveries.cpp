class Solution {
public:
    long long minimumTime(vector<int>& d, vector<int>& r) {
      long long d1=d[0];
      long long d2=d[1];
      long long r1=r[0];
      long long r2=r[1];
     long long LCM=lcm(r1,r2);
    long long left=1;
    long long right=1e15;
    long long ans=right;
  while(left<=right){
      long long mid=left+(right-left)/2;
      long long del1=mid-(mid/r1);   //jo bhi total hour choose kra hai usse recharge wale hours hata doo
      long long del2=mid-(mid/r2);
      long long total=mid-mid/LCM;  //jab drone 1 aur drone 2 dono sath recharge honge
      if(del1>=d1 && del2>=d2 && d1+d2<=total){
          ans=mid;
          right=mid-1;
      }
      else{
          left=mid+1;
      }
   }
        return ans;
    }
};
