class Solution {
public:
int MOD=12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();

        
        vector<int>nums;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                nums.push_back(grid[i][j]);
            }
        }
        int sizee=nums.size();
        vector<int>pref(sizee);
        vector<int>suff(sizee);
        pref[0]=nums.front()%MOD;
        suff[sizee-1]=nums.back()%MOD;

        for(int i=1;i<sizee;i++){
            pref[i]=(1LL*pref[i-1]*nums[i])%MOD;
        }

        for(int i=sizee-2;i>=0;i--){
            suff[i]=(1LL*suff[i+1]*nums[i])%MOD;
        }

        vector<int>ans(sizee);

        ans[0]=suff[1];
        cout<<ans[0]<<" ";
        ans[sizee-1]=pref[sizee-2];

        for(int i=1;i<sizee-1;i++){
            ans[i]=(1LL*pref[i-1]*suff[i+1])%MOD;
            cout<<ans[i]<<" ";
        }
        cout<<ans[sizee-1];

        vector<vector<int>>result(n,vector<int>(m));
        int number=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                result[i][j]=ans[number];
                number++;
            }
        }

        return result;





    }
};
