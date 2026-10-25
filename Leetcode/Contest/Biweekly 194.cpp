class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {

        int peak=0,valley=0;

        for(int i=1;i<nums.size()-1;i++){

            if(nums[i]>nums[i-1] and nums[i]>nums[i+1]) peak+=nums[i];

              if(nums[i]<nums[i-1] and nums[i]<nums[i+1]) valley+=nums[i];
        }

        return peak-valley;
        
    }
};

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {

        long long l=0,count=0;
        
        for(int h=0;h<nums.size();h++){

            if(nums[h]>=minK and nums[h]<=maxK) count+=h-l+1;

            else l=h+1;            
            
        }

        return count;
        
    }
};

/*

i to j ke distint character == j to k distinct character

so agr har range ke distinct character pta hoo so it can be easy

so can we use seg tree?

1 2 3 3 4 4 5 6 

first lets try brute force


if n<=2000

can we precomputer distincs of all ranges


TLE!

worked letssgoo!
*/
class Solution {
public:
    int countMagicalPairs(string s) {

        int n=s.size(),ans=0;

        vector<vector<int>>uniques(n,vector<int>(n,0));

        for(int i=0;i<n;i++){

            unordered_set<char>st;

            for(int j=i;j<n;j++){

                st.insert(s[j]);

                uniques[i][j]=st.size();
                
            }
        }


        for(int j=0;j<n-1;j++){

            unordered_map<int,int>mp;

            for(int i=0;i<=j;i++){

                mp[uniques[i][j]]++;
            }

            for(int k=j+1;k<n;k++){

                if(mp.count(uniques[j+1][k])) ans+=mp[uniques[j+1][k]];
                 
                //cout<<"okay till here"<<endl;
            }

            //cout<<" i j k ->"<<i<<" "<<j <<" "<<k<<endl;

            //cout<<ans<<endl;

           
            
        }

        return ans;
        
        
    }
};
