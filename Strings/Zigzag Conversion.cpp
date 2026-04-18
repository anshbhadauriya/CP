class Solution {
public:
    string convert(string s, int rows) {

        if(rows==1) return s;

        // int col=(s.size()/2)+10;

        vector<vector<char>>grid(1001,vector<char>(500,'@'));  //600 is random letsss see how less we can take
        int m=grid[0].size();
        //go down 
        //top right
        //down

        int n=s.size();
        int i=0,j=0,curr=0;
        while(true){
        while(i<rows and curr<n){

            grid[i][j]=s[curr];
            curr++;
            if(i==rows-1) break;
            i++;
        }

        if(curr==n) break;

        ++j;
        --i;

        while(i>=0 and curr<n){
            grid[i][j]=s[curr];
            curr++;
            j++;
            if(i==0) break;
            i--;
        }
        if(curr==n) break;

        ++i;
        }

        string ans="";

        for(int i=0;i<1001;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!='@') ans+=grid[i][j];
            }
        }

        return ans;


        




    }
};
