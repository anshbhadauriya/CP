class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {

        int n=grid.size();
        int m=grid[0].size();

        vector<int>nums;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                nums.push_back(grid[i][j]);
            }
        }

        sort(nums.begin(),nums.end());  //to find median sort krna pdta hai

        int median=nums[nums.size()/2],total_operations=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int diff=abs(median-grid[i][j]);

                if(diff%x!=0) return -1;


                int curr_operations=diff/x;  //kitne operations lgege to convert to median
                total_operations+=curr_operations;
            }
        }

        return total_operations;

        
    }
};
