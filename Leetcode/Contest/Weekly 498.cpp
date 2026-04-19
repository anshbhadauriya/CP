Q1->
  class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        int mini=INT_MAX;
        vector<int>minimum(nums.size());

        for(int i=nums.size()-1;i>=0;i--){
            mini=min(mini,nums[i]);
            minimum[i]=mini;
        }
int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
            int inst=maxi-minimum[i];
            if(inst<=k) return i;
        }
        return -1;
        
    }
};
Q2->
  class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        int mini=INT_MAX;
        vector<int>minimum(nums.size());

        for(int i=nums.size()-1;i>=0;i--){
            mini=min(mini,nums[i]);
            minimum[i]=mini;
        }
int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
            int inst=maxi-minimum[i];
            if(inst<=k) return i;
        }
        return -1;
        
    }
};

Q3->
  class Solution {
public:
    static bool comperator(vector<int>&a,vector<int>&b){
        return a[2]>b[2];
    }
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        //source is colored only 
        //each cell try to have max value color

        vector<vector<pair<int,int>>>grid(n,vector<pair<int,int>>(m,{0,INT_MAX}));  //color,steps

        queue<pair<pair<int,int>,pair<int,int>>>q;


        //pehle large color ko pohochao cell me

        sort(sources.begin(),sources.end(),comperator);

        for(auto x:sources){
            int row=x[0],col=x[1],color=x[2];
            grid[row][col]={color,0};
            
            q.push({{row,col},{color,0}});
        }

        
int steps=0;
        while(!q.empty()){

            int size=q.size();

            while(size--){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int color=q.front().second.first;
            // int steps=q.front().second.second;

            q.pop();
            if(color<grid[row][col].first) continue;

if(row+1<n){
    if(steps+1<grid[row+1][col].second){
                grid[row+1][col]={color,steps+1};
                q.push({{row+1,col},{color,steps+1} });
    }
    else if(steps+1==grid[row+1][col].second and color>grid[row+1][col].first){
        grid[row+1][col].first=color;
    }
            }

            if(row-1>=0 ){

                if(steps+1<grid[row-1][col].second){
                grid[row-1][col]={color,steps+1};
                q.push({{row-1,col},{color,steps+1} });
            }
                else if(steps+1==grid[row-1][col].second and color>grid[row-1][col].first){
                    grid[row-1][col].first=color;
                }
            }

            if(col+1<m){

                if(steps+1<grid[row][col+1].second){
                    
                
                grid[row][col+1]={color,steps+1};
                q.push({{row,col+1},{color,steps+1} });
                }
                else if(steps+1==grid[row][col+1].second and color>grid[row][col+1].first){
                    grid[row][col+1].first=color;
                }
                
            }

            if(col-1>=0){

                if(steps+1<grid[row][col-1].second){

                grid[row][col-1]={color,steps+1};
                q.push({{row,col-1},{color,steps+1} });
                }
                else if(steps+1==grid[row][col-1].second and color>grid[row][col-1].first){

                    grid[row][col-1].first=color;
                }
                
            }
            }
            steps++;

            
        }

        vector<vector<int>>ans(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j]=grid[i][j].first;
            }
        }

        return ans;
        

        
        
    }
};
