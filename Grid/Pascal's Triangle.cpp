class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>>result;
        
        for(int i=1;i<=numRows;i++){
            
            vector<int>current;
            
            if(i==1){
                result.push_back({1});
                continue;
            }
            
            vector<int>&prev=result.back();
            
            for(int j=0;j<=prev.size();j++){
                
                if(j==0 or j==prev.size()){
                    current.push_back(1);
                }
                else{
                    
                    current.push_back(prev[j-1]+prev[j]);
                }
            }
            
            result.push_back(current);
            
        }
        
        return result;
        
    }
};
