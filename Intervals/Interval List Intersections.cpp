Brute Force->

class Solution {
public:
bool isIntersection(int a1,int b1,int a2,int b2){
    if(b1 < a2 or b2 < a1) 
        return false;
      return true;
}
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {

        vector<vector<int>>result;
        int i=0,j=0;
       for(int i=0;i<firstList.size();i++){
        for(int j=0;j<secondList.size();j++){
           int a1=firstList[i][0];
           int b1=firstList[i][1];
           int a2=secondList[j][0];
           int b2=secondList[j][1];

           if(isIntersection(a1,b1,a2,b2)){
            int st=max(a1,a2);
            int end=min(b1,b2);
            result.push_back({st,end});
           }
        }
        }

        return result;
        
    }
};
